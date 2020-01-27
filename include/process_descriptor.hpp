#ifndef __PROCESS_DESCRIPTOR_HPP
#define __PROCESS_DESCRIPTOR_HPP

#include <string>
#include <memory>

namespace compute_grid
{

class ProcessStatus
{
public:
};

class ProcessExitInfo
{
public:
    ProcessExitInfo();
};

class ProcessDescriptor
{
private:
    std::string jobid_;
    ProcessStatus status_;
    std::shared_ptr<ProcessExitInfo> exit_info;    
};

} // namespace compute_grid

#endif
