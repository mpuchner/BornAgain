"""
Plot form factors.
"""
import bornagain as ba
from bornagain import nm, deg
import bornplot as bp

det = bp.Detector(200, -5, 5, -5, 5)
n = 4
results = []
for i in range(n):
    omega = 90*i/(n - 1)
    title = r'$\omega=%d^\circ$' % omega
    ff = ba.FormFactorSawtoothRippleBox(25*nm, 10*nm, 8*nm,
                                        5*nm)
    trafo = ba.RotationZ(omega*deg)
    data = bp.run_simulation(det, ff, trafo)
    results.append(bp.Result(i, data, title))

bp.make_plot(results, det, "ff_SawtoothRipple")
