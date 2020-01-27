#ifndef __PROCESS_MONITOR_HPP
#define __PROCESS_MONITOR_HPP

#include <vector>

namespace compute_grid
{
    
class ProcessMonitor
{
public:
    ~ProcessMonitor();

    using ProcessDescriptors = std::vector<ProcessDescriptor>;

    //------------------------------------------------------
    // ProcessMonitor()
    // Singleton factory method.
    // Return reference to the ProcessMonitor's instance.
    static ProcessMonitor& GetInstance();

    //------------------------------------------------------- 
    // MakeProcess()
    // :param descr: process descriptor 
    // Retrieve status of the specified process 
    // Return an instance of the ProcessDescrptor with 
    // current status set.
    ProcessDescriptor MakeProcess(JobTemplate job_template, bool local);
    //------------------------------------------------------- 
    // MakeProcesses()
    // :param descr: process descriptor 
    // Retrieve status of the specified process 
    // Return an instance of the ProcessDescrptor with 
    // current status set.
    ProcessDescriptors MakeProcesses(JobTemplate job_template, bool local);
    //------------------------------------------------------- 
    // GetProcessStatus()
    // :param descr: process descriptor 
    // Retrieve status of the specified process 
    // Return an instance of the ProcessDescrptor with 
    // current status set.
    ProcessDescriptor GetProcessStatus(ProcessDescriptor);
    //------------------------------------------------------- 
    // GetExitInfo()
    // :param descr: process descriptor 
    // Extract exit info for the specified process 
    // if the process is in stopped / terminated state. 
    // Return an instance of the ProcessDescrptor with 
    // exit status member set.
    ProcessDescriptor GetExitInfo(ProcessDescriptor descr); 

private:
    ProcessMonitor();
    ProcessMonitor(ProcessMonitor const&) = delete;
    ProcessMonitor& operator= (ProcessMonitor&) = delete;
};

} // namespace compute_grid

#endif // __PROCESS_MONITOR_HPP
