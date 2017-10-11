#include "projectile.hpp"


const double m = 1;
const double g = 9.8066;
const double dt = 0.001;
const double q= 1;
const double k= 0.5;
const double w =2;
const double Eo=1;


auto force(TState s) {
  return (q*(Eo/sqrt(2))*(VecR3<double>{cos((k*s.position.z)-(w*s.t)),sin((k*s.position.z)-(w*s.t)),0.}));
}

auto euler_step(TState s, VecR3<double> accel){
  TState next;
  next.t = s.t + dt;
  next.position = s.position + (s.velocity * dt);
  next.velocity = s.velocity + (accel* dt);
  return next;
}

auto verlet_step(TState s,VecR3<double>accel){
  TState next;
  next.t = s.t + dt;
  next.position = s.position + (s.velocity * dt)+(0.5*(accel*dt*dt));
  next.velocity = s.velocity + ((((accel)+(force(next)/m))/2.00)*dt);
  return next;
}

void n_steps(unsigned n, TState state0) {
  print_tstate(state0);
  if (n == 0)
    return;
  else {
    auto state = state0;
    for (unsigned k = 0; k < n; ++k) {
      state = verlet_step(state, force(state)/ m);
      print_tstate(state);
    }
  }
}

int main() {
  n_steps(7000, TState{0., {((-Eo)/(w*w)*sqrt(2)),0,0}, {0, (Eo/(w*sqrt(2))),-0.25}});
  return 0;
}
