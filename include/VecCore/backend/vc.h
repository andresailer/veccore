#ifndef VECCORE_VECTOR_BACKEND_H
#define VECCORE_VECTOR_BACKEND_H

#include <VecCore/core/simd.h>

#ifdef VECCORE_ENABLE_SIMD

#include <cmath>
#include <cstdint>

#include <Vc/Vc>

namespace VecCore {
namespace Backend {

template <typename FloatT = double>
class Vector {
  public:
    static const bool EarlyExit = true;

    // floating point types

    typedef FloatT               Real_t;
    typedef float_t              Float_t;
    typedef double_t             Double_t;

    typedef Vc::Vector<Real_t>   Real_v;
    typedef Vc::Vector<Float_t>  Float_v;
    typedef Vc::Vector<Double_t> Double_v;

    // integer types

    typedef int                  Int_t;
    typedef int16_t              Int16_t;
    typedef int32_t              Int32_t;
    typedef int64_t              Int64_t;

    typedef Vc::Vector<Int_t>    Int_v;
    typedef Vc::Vector<Int16_t>  Int16_v;
    typedef Vc::Vector<Int32_t>  Int32_v;
    typedef Vc::Vector<Int64_t>  Int64_v;

    typedef unsigned int         UInt_t;
    typedef uint16_t             UInt16_t;
    typedef uint32_t             UInt32_t;
    typedef uint64_t             UInt64_t;

    typedef Vc::Vector<UInt_t>   UInt_v;
    typedef Vc::Vector<UInt16_t> UInt16_v;
    typedef Vc::Vector<UInt32_t> UInt32_v;
    typedef Vc::Vector<UInt64_t> UInt64_v;
};

}
}

#else

// fallback to scalar backend if Vc is not available

#include <backend/scalar.h>

namespace VecCore {
namespace Backend {

template <typename T> using Vector = Scalar<T, true>;

}
}

#endif
#endif