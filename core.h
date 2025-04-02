#include 

namespace wengine {
  class Vector3 {
    public:
        real x;
        real y;
        real z;
        
        // Default constructor inits zero vector
        Vector3() : x(0), y(0), z(0) {}
        // Expllicit constructor inits vector with given values
        Vector3(const real x, const real y, const real z) : x(x), y(y), z(z) {}
        
        void invert()
        {
            x = -x;
            y = -y;
            z = -z;
        }
  };
}
