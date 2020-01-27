#ifndef __DETAIL_MONITOR_COMMANDS_HPP
#define __DETAIL_MONITOR_COMMANDS_HPP

namespace compute_grid
{

namespace detail
{

// MonitorCommand.
// Collection of commands executed by process monitor.
//
//
//

using ProcessDescriptorPromise = std::promise<ProcessDescriptor>;
using ProcessDescriptorCollPromise = std::promise<std::vector< ProcessDescriptor >>;


class MonitorCommand
{
public:
    virtual ~MonitorCommand();
    virtual void Execute() = 0;
};


class BackgroundProcessingCommand : public MonitorCommand
{
public:
    void Execute();
};

class MakeProcessCommand : public MonitorCommand
{
public:
    MakeProcessCommand(ProcessDescriptor descr);

    void Execute();
    ProcessDescriptor Get();

private:
    ProcessDescriptor descr_;
    std::unique_ptr<ProcessDescriptorPromise> promise_;
};


class MakeProcessesCommand : public MonitorCommand
{
public:
    MakeProcessesCommand(ProcessDescriptor descr);

    void Execute();
    ProcessDescriptor Get();

private:
    ProcessDescriptor descr_;
    std::unique_ptr<ProcessDescriptorCollPromise> promise_;
};


class ProcessStatusCommand : public MonitorCommand
{
public:
    ProcessStatusCommand(ProcessDescriptor descr);

    void Execute();
    ProcessDescriptor Get();

private:
    ProcessDescriptor descr_;
    std::unique_ptr<ProcessDescriptorPromise> promise_;
};

class ProcessExitInfoCommand : public MonitorCommand
{
public:
    ProcessExitInfoCommand(ProcessDescriptor descr);

    void Execute();
    ProcessDescriptor Get();

private:
    ProcessDescriptor descr_;
    std::unique_ptr<ProcessDescriptorPromise> promise_;
};


} // namespace detail


} // namespace compute_grid

#endif
