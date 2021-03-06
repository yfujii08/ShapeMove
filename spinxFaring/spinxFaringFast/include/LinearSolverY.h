// ============================================================================
// SpinXForm -- LinearSolver.h
// Keenan Crane
// August 16, 2011
//
// LinearSolver is used to solve the sparse linear system
//
//    Ax = b
//
// where A is a positive-definite matrix.  Depending on which distribution
// of SpinXForm you have installed, solve() uses either a sparse Cholesky
// factorization or a simple conjugate gradient (CG) solver.  The advantage
// of using Cholesky as opposed to an iterative solver like CG is that
// matrices can be prefactored.  For instance, in the eigenvalue problem we
// have to iteratively solve systems of the form
//
//    A x_{n+1} = x_n.
//
// Since this system uses the same matrix A every time, most of the work can
// be done up front by prefactoring A.  Since prefactorization dominates the
// overall cost, solving the eigenvalue problem with Cholesky costs about as
// much as solving a single linear system using either method.
//

#ifndef SPINYFORM_LINEAR_SOLVER_H
#define SPINYFORM_LINEAR_SOLVER_H

#include <vector>
#include "QuaternionMatrixY.h"
#include "CMWrapperY.h"

namespace spiny{
using namespace cm;
using namespace std;

class LinearSolver
{
   public:
      static void solve( Factor& A,
                         vector<Quaternion>& x,
                         const vector<Quaternion>& b );
      // solves the linear system Ax = b where A is positive-semidefinite

      static void toReal( const vector<Quaternion>& uQuat,
                          Dense& uReal );
      // converts vector from quaternion- to real-valued entries

      static void toQuat( const Dense& uReal,
                          vector<Quaternion>& uQuat );
      // converts vector from real- to quaternion-valued entries
};
}
#endif
