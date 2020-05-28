#pragma once


#include "EventBase.h"
#include <thread>

//#define GDP_RECONNECT_TIMER_ID 171
#define GDP_RECONNECT_TIMEOUT 2 // seconds
#define GDP_MAX_RECONNECT_TIMEOUT 256 // seconds

class GEventBaseWithAutoReconnect : public GEventBase
{
public:
    GEventBaseWithAutoReconnect(int reconn_min = GDP_RECONNECT_TIMEOUT, int reconn_max = GDP_MAX_RECONNECT_TIMEOUT);
    ~GEventBaseWithAutoReconnect();

    bool do_connect(unsigned short port, void *arg);
    GEventHandler* connector(); 

protected:
    virtual void on_error(GEventHandler *h);
    virtual bool on_timeout(GDP_PER_TIMER_DATA *gptd);

    virtual void on_connect_break(); 
    virtual bool on_connected(GEventHandler *app);

protected:
    void do_reconnect(void *arg);

protected:
    unsigned short m_port; 
    GEventHandler* m_app;
    GEventHandler* m_htimer; 
    void* m_timer;
    int m_reconn_min; 
    int m_reconn_max; 
    int m_reconn_curr;
    //std::thread *m_thr;
};
