
# // #include "inc/miniRT.h"
# // #include "inc/objects.h"
# // #include <stdio.h>

# // int32_t	main(void)
# // {
# // 	t_sphere	*sph;
# // 	t_ambient	*amb;

# // 	sph = sphere();
# // 	amb = ambient();
# // 	printf("%f, %f, %f\n", sph->color.x, sph->color.y, sph->color.z);
# // 	printf("%f, %f, %f\n", amb->color.x, amb->color.y, amb->color.z);
# // 	return (0);
# // }

import numpy as np

# Original matrix 'a'
a = np.array([
    [4.200939, 1.971915, 3.915496, 3.992200],
    [4.558237, 0.987757, 1.676114, 3.841148],
    [1.388874, 2.769850, 2.386985, 3.144355],
    [1.823922, 2.567005, 4.761149, 4.580975]
], dtype=np.float64)

# Your computed inverse
inverted_a = np.array([
    [0.454032, -0.063391, 0.046199, -0.374234],
    [0.317694, -0.306533, 0.721548, -0.515101],
    [0.434002, -0.360514, -0.302421, 0.131650],
    [-0.809869, 0.571702, -0.108407, 0.519111]
], dtype=np.float64)

# Test: multiply a * inverted_a
identity = a @ inverted_a

print("Result of a * inverted_a:")
print(identity)

# Check how close it is to the true identity matrix
print("\nDifference from identity:")
print(identity - np.eye(4))

# Optional: max absolute error
print("\nMax absolute error:", np.max(np.abs(identity - np.eye(4))))
