#pragma once

#include "hal_core/defines.h"

namespace hal
{
    namespace dataflow
    {
        /* forward declaration */
        struct Grouping;

        namespace group_by_successors_predecessors_iteratively
        {
            std::shared_ptr<Grouping> process(const std::shared_ptr<Grouping>& state, bool successors);

        }    // namespace group_by_successors_predecessors_iteratively
    }        // namespace dataflow
}