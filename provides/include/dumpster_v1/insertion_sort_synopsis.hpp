#pragma once

namespace dumpster_v1 {

template <class RandomIt, class Less, class IsSentinel>
void insertion_sort(RandomIt values, Less less, IsSentinel is_sentinel);

} // namespace dumpster_v1
