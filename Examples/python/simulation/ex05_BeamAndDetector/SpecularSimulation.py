"""
R and T coefficients in multilayer, Specular simulation.
"""
import numpy
import pylab
from bornagain import *


alpha_i_min, alpha_i_max = 0.0, 2.0  # incoming beam


def get_sample():
    """
    Build and return the sample representing the layers with correlated roughness.
    """
    m_ambience = HomogeneousMaterial("ambience", 0.0, 0.0)
    m_part_a = HomogeneousMaterial("PartA", 5e-6, 0.0)
    m_part_b = HomogeneousMaterial("PartB", 10e-6, 0.0)
    m_substrate = HomogeneousMaterial("substrate", 15e-6, 0.0)

    l_ambience = Layer(m_ambience)
    l_part_a = Layer(m_part_a, 5.0*nanometer)
    l_part_b = Layer(m_part_b, 10.0*nanometer)
    l_substrate = Layer(m_substrate)

    roughness = LayerRoughness()
    roughness.setSigma(1.0*nanometer)
    roughness.setHurstParameter(0.3)
    roughness.setLatteralCorrLength(500.0*nanometer)

    my_sample = MultiLayer()

    # adding layers
    my_sample.addLayer(l_ambience)

    n_repetitions = 10
    for i in range(n_repetitions):
        my_sample.addLayerWithTopRoughness(l_part_a, roughness)
        my_sample.addLayerWithTopRoughness(l_part_b, roughness)

    my_sample.addLayerWithTopRoughness(l_substrate, roughness)
    # my_sample.setCrossCorrLength(1e-4)

    return my_sample


def get_simulation():
    """
    Create and return off-specular simulation with beam and detector defined
    """
    simulation = SpecularSimulation()
    simulation.setBeamParameters(1.54*angstrom, 1000, alpha_i_min*degree, alpha_i_max*degree)
    return simulation


def run_simulation():
    """
    Run simulation and plot results
    """
    sample = get_sample()
    simulation = get_simulation()
    simulation.setSample(sample)
    simulation.runSimulation()

    # plotting results for several selected layers
    selected_layers = [0, 1, 20, 21]
    alpha_angles = simulation.getAlphaAxis().getBinCenters()

    dpi = 72.
    xinch = 1024 / dpi
    yinch = 768 / dpi
    fig = pylab.figure(figsize=(xinch, yinch))

    nplot = 1
    for layer_index in selected_layers:

        R = []
        for coeff in simulation.getScalarR(layer_index):
            R.append(numpy.abs(coeff))

        T = []
        for coeff in simulation.getScalarT(layer_index):
            T.append(numpy.abs(coeff))

        pylab.subplot(2, 2, nplot)
        pylab.ylim(ymax=50.0, ymin=1e-06)
        pylab.xlabel(r'$\alpha_f$ (rad)', fontsize=16)
        pylab.semilogy(alpha_angles, R)
        pylab.semilogy(alpha_angles, T)
        pylab.legend(['|R| layer #'+str(layer_index), '|T| layer #'+str(layer_index)], loc='upper right')
        nplot = nplot + 1


    pylab.show()


if __name__ == '__main__':
    run_simulation()