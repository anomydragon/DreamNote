#include <Dream.h>
#include <Core/EntryPoint.h>

class DreamNotes : public Dream::Application
{
public:
    DreamNotes()
    {

    }

    ~DreamNotes()
    {

    }
};

Dream::Application *Dream::CreateApp()
{
    return new DreamNotes();
}
