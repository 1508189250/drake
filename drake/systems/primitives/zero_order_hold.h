#pragma once

#include <memory>

#include "drake/common/drake_copyable.h"
#include "drake/common/eigen_types.h"
#include "drake/systems/framework/context.h"
#include "drake/systems/framework/siso_vector_system.h"

namespace drake {
namespace systems {

/// A ZeroOrderHold block with input `u`, which may be discrete or continuous,
/// and discrete output `y`, where the y is sampled from u with a fixed period.
/// @ingroup primitive_systems
template <typename T>
class ZeroOrderHold : public SisoVectorSystem<T> {
 public:
  DRAKE_NO_COPY_NO_MOVE_NO_ASSIGN(ZeroOrderHold)

  /// Constructs a ZeroOrderHold system with the given @p period_sec, over a
  /// vector-valued input of size @p size.
  ZeroOrderHold(const T& period_sec, int size);

  /// In a zero-order hold, the output depends only on the state, so there is
  /// no direct-feedthrough.
  bool has_any_direct_feedthrough() const override { return false; }

 protected:
  /// Sets the output port value to the value that is currently latched in the
  /// zero-order hold.
  void DoCalcVectorOutput(
      const Context<T>& context,
      const Eigen::VectorBlock<const VectorX<T>>& input,
      const Eigen::VectorBlock<const VectorX<T>>& state,
      Eigen::VectorBlock<VectorX<T>>* output) const override;

  /// Latches the input port into the discrete state.
  void DoCalcVectorDiscreteVariableUpdates(
      const Context<T>& context,
      const Eigen::VectorBlock<const VectorX<T>>& input,
      const Eigen::VectorBlock<const VectorX<T>>& state,
      Eigen::VectorBlock<VectorX<T>>* discrete_updates) const override;
};

}  // namespace systems
}  // namespace drake
