# `livecode-projectile`
---
![](https://travis-ci.org/timtro/livecode-projectile.svg?branch=master)

A simple implementation of an Euler integrator for projectile motion. 

### 1. 

![](/home/mahum/Pictures/verlet.png)

### 2. In the context of Question 1, how should the trajectory produced by the Verlet algorithm differ from the Euler integrator we used in the livecode?

The obvious difference between the Verlet integrator and Euler integrator would be that the latter is 2D, while the Verlet is in 3D. The Verlet algorithm has more stability than the Euler integrator, which is much simpler. Uniform update rate or the ability to accurately identify positions at a small time delta into the past, is what stability depends greatly on. Euler integration is fine for estimates and quick calculations but has many problems due to its errors, therefore it is good for an estimate for the trajectory. Since there are errors, it is not accurate, unlike the Verlet algorithm, which is more accurate resulting in a more accurate trajectory.  



### 3. In livecode-projectile.hpp, we defined a type-constructor called VecR2 along with operators for addition and scalar multiplication. Does the VecR2 type constitute a vector space? If yes, prove it. If not, explain why not.

A vector space is a set of values with two well-behaved operations; vector addition and scalar multiplication. For these operations, the term well-behaved means axioms, like closure under addition, associativity, commutativity, additive inverses, and identity. For VecR2 to be a vector space, it would need to follow all the axioms, but it does not. With operations of addition and scalar multiplication, it resembles a vector space but VecR2 does not constitute an actual vector space.
