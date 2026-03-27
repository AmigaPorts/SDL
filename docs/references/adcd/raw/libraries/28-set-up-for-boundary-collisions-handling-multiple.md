# 28 / / Set Up For Boundary Collisions / Handling Multiple Collisions


When multiple elements collide within the same display field, the
following set of sequential calls to the collision routines occurs:

  * The system issues each call in a sorted order for GELs starting at

    the upper left-hand corner of the screen and proceeding to the right
    and down the screen.
  * For any colliding GEL pair, the system issues only one call, to the

    collision routine for the object that is the topmost and leftmost of
    the pair.
