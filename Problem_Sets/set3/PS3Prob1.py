import numpy as np
from gurobipy import*
WW = Model()

Set0 = (1,1,0,0,0,0,0,1)
Set1 = (1,0,0,0,1,1,0,0)
Set2 = (0,0,1,0,0,1,0,0)
Set3 = (0,1,0,0,0,0,1,1)
Set4 = (0,0,0,1,1,0,0,0)
map = (Set0, Set1, Set2, Set3, Set4)

x = WW.addVars(5, lb=np.zeros(5), vtype=GRB.BINARY, name="if_chooseSet")
WW.setObjective(quicksum(x[i] for i in range(5)), GRB.MINIMIZE)
c1 = WW.addConstrs(quicksum(x[i]*map[i][j] for i in range(5)) >=1 for j in range (8))

WW.optimize()
WW.printAttr('X')
