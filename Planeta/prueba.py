import gravedad
import Cy_gravedad
import time

## Initial planet Python
tierra = gravedad.Planet()
tierra.x = 100* 10**3
tierra.y = 300* 10**3
tierra.z = 700* 10**3
tierra.vx = 2.000 * 10**3
tierra.vy = 29.87 * 10**3
tierra.vy = 0.037 * 10**3

tierra.m = 5.9742 * 10**3

## Initial planet Python
tierraCy = Cy_gravedad.Planet()
tierraCy.x = 100* 10**3
tierraCy.y = 300* 10**3
tierraCy.z = 700* 10**3
tierraCy.vx = 2.000 * 10**3
tierraCy.vy = 29.87 * 10**3
tierraCy.vy = 0.037 * 10**3
tierraCy.m = 5.9742 * 10**3

time_span = 400
n_steps = 2000000

initial = time.time()
gravedad.step_time(tierra, time_span, n_steps)
tiempoPy = time.time() - initial

initial = time.time()
Cy_gravedad.step_time(tierraCy, time_span, n_steps)
tiempoCy = time.time() - initial

SpeedUp = round(tiempoPy/tiempoCy, 3)

print("tiempo Py: {}\n".format(tiempoPy))
print("tiempo Cy: {}\n".format(tiempoCy))
print("SpeedUp: {}\n".format(SpeedUp))