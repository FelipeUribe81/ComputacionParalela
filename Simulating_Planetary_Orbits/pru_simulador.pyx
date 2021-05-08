#cython: language_level=3
#!/usr/bin/env python3

#import math
#from turtle import *
cimport cython 
from cython cimport cdivision
from cython.parallel import prange

cdef extern from "math.h":
        double cos(double x) 
        double sin(double x) 
        double sqrt(double x) 
        double atan2(double x, double y) 
        

# The gravitational constant G
cdef double G = 6.67428e-11

# Assumed scale: 100 pixels = 1AU.
cdef double AU = (149.6e6 * 1000)     # 149.6 million km, in meters.
    
#cdef double AU = (149.6e6 * 1000)     # 149.6 million km, in meters.

@cython.cdivision(True)
cdef double getSCALE():
    return 250 / AU

cdef double SCALE = getSCALE() 


#class Body(Turtle):
cdef class Body(object):
    
    """Subclass of Turtle representing a gravitationally-acting body.

    Extra attributes:
    mass : mass in kg
    vx, vy: x, y velocities in m/s
    px, py: x, y positions in m
    """
    cdef public double vx, vy, px, py, mass
    cdef public char* name

    name = 'Body'
    mass = 0.0
    vx = vy =  0.0
    px = py = 0.0
    
    @cython.cdivision(True)
    cdef tuple attraction(Body self, Body other):
        """(Body): (fx, fy)

        Returns the force exerted upon this body by the other body.
        """
        # Report an error if the other object is the same as this one.
        if self is other:
            raise ValueError("Attraction of object %r to itself requested"
                             % self.name)

        # Compute the distance of the other body.
        sx, sy = self.px, self.py
        ox, oy = other.px, other.py
        dx = (ox-sx)
        dy = (oy-sy)
        d = sqrt(dx**2 + dy**2)

        # Report an error if the distance is zero; otherwise we'll
        # get a ZeroDivisionError exception further down.
        if d == 0:
            raise ValueError("Collision between objects %r and %r"
                             % (self.name, other.name))

        # Compute the force of attraction
        cdef double f = (G * self.mass * other.mass) / (d**2)

        # Compute the direction of the force.


        theta = atan2(dy, dx)
        fx = cos(theta) * f
        fy = sin(theta) * f
        return fx, fy

def update_info(step, bodies):
    """(int, [Body])
    
    Displays information about the status of the simulation.
    """
    print('Step #{}'.format(step))
    for body in bodies:
        s = '{:<8}  Pos.={:>6.2f} {:>6.2f} Vel.={:>10.3f} {:>10.3f}'.format(
            body.name, body.px/AU, body.py/AU, body.vx, body.vy)
        print(s)
    print()

def loop(bodies):
    """([Body])

    Never returns; loops through the simulation, updating the
    positions of all the provided bodies.
    """
    cdef double timestep = 24*3600  # One day
    
    #for body in bodies:
        #body.penup()
        #body.hideturtle()

    cdef int step = 1
    cdef dict force
    cdef double fx, fy
    cdef double total_fx, total_fy
    """ Step to need round to earth"""
    while (step <= 365*1000):
        #update_info(step, bodies)
        step += 1
       
        force = {}
        for body in bodies:
            # Add up all of the forces exerted on 'body'.
            total_fx = total_fy = 0.0
            for other in bodies:
                # Don't calculate the body's attraction to itself
                if body is other:
                    continue
                fx, fy = body.attraction(other)
                total_fx += fx
                total_fy += fy

            # Record the total force exerted.
            #force[body] = (total_fx, total_fy)

        # Update velocities based upon on the force.
        for body in bodies:
            #fx, fy = force[body]
            body.vx += fx / body.mass * timestep
            body.vy += fy / body.mass * timestep

            # Update positions
            body.px += body.vx * timestep
            body.py += body.vy * timestep
            
