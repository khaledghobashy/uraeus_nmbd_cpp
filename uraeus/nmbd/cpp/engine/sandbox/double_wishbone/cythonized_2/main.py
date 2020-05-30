import test
import numpy as np

class functions(object):

    @classmethod
    def zero(cls):
        def func(t):
            return 0.0
        return func
    
    @classmethod
    def constant(cls):
        def func(t):
            return 546.0
        return func

sim = test.PySimulation()
sim.construct_configuration(b"double_wishbone_direct_acting.json")

def constant(t):
    #print('called "constant" with t = %s'%t)
    travel = 546 + 130*np.sin(t)
    #print('travel = %s'%travel)
    return 546.0


print('Setting wheel_travel functions\n')
sim.set_UF_mcr_wheel_travel_func(functions.constant())
sim.set_UF_mcl_wheel_travel_func(functions.constant())
print('End wheel_travel functions\n')

def zero(t):
    #print('called "zero" with t = %s'%t)
    return 0.

print('Setting wheel_lock functions\n')
sim.set_UF_mcr_wheel_lock_func(functions.zero())
sim.set_UF_mcl_wheel_lock_func(functions.zero())
print('End wheel_lock functions\n')


sim.solve(3.14*2, 200)

#print('Done Solving!')

#sim.save_results()

