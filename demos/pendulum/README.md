# PENDULUM
**STANDALONE TOPOLOGY**

------------------------------------------

### **Summary**
A pendulum is a weight suspended from a pivot so that it can swing freely. It consists of ywo bodies, the pendulum and the ground, attached together through a pin/revolute joint. More general information about the pendulum can be found on [wikipedia](https://en.wikipedia.org/wiki/Pendulum).

------------------------------------------

### **Topology Layout**
The mechanism consists of 1 Body + 1 Ground. Therefore, total system coordinates -including the ground- is 
$$n=n_b\times7 = 2\times7 = 14$$ 

where $n_b$ is the total number of bodies.  [^1]

The list of bodies is given below:

- Pendulum body $body$.

The system connectivity is as follows:
- Pendulum $body$ is connected to the ground by a revolute joint, resulting in constraint equations $n_{c,rev} = 5$

<br/>
<br/>

<center>

| Joint Name  | Body i         | Body j         | Joint Type | $n_c$ |
|:-----------:|:-------------- |:-------------- | ---------- | ----- |
| a           | Ground         | Pendulum       | Revolute   | 5     |

</center>

<br/>

The degrees of freedom of the system can be calculated as:
    $$n-( n_{c,rev}+n_{c,P}+n_{c,g}) = 14 - (5 + (1 \times 1) + 7) = 14 - 13 = 1$$

where the $n_{c,P}$ and $n_{c,g}$ represents the constraints due to euler-parameters normalization equations and the ground-constraints respectively.


<br/>

-------------------------------------------------------



[^1]: The tool uses [euler-parameters](https://en.wikibooks.org/wiki/Multibody_Mechanics/Euler_Parameters) -which is a 4D unit quaternion- to represents bodies orientation in space. This makes the generalized coordinates used to fully define a body in space to be **7,** instead of **6**, it also adds an algebraic equation to the constraints that ensures the unity/normalization of the body quaternion. This is an important remark as the calculations of the degrees-of-freedom depends on it.

