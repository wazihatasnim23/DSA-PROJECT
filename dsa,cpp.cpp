#include<bits/stdc++.h>
using namespace std;

#define MAX 1000

int left(int i){ return 2*i+1; }
int right(int i){ return 2*i+2; }
int parent(int i){ return (i-1)/2; }


class MaxHeap {
public:
    pair<int,int> heap[MAX]; // (priority, ticketId)
    int size;

    MaxHeap(){
        size = 0;
    }

    bool isempty(){
        return size == 0;
    }

    pair<int,int> getmax(){
        if(size == 0) return {-1,-1};
        return heap[0];
    }

    void insert(pair<int,int> key){
        if(size == MAX) return;

        heap[size] = key;
        int pos = size;
        size++;


        while(pos > 0 && compare(heap[parent(pos)], heap[pos])){
            swap(heap[parent(pos)], heap[pos]);
            pos = parent(pos);
        }
    }

    bool deleteMax(){
        if(size == 0) return false;

        heap[0] = heap[size-1];
        size--;

        int pos = 0;

        while(true){
            int l = left(pos);
            int r = right(pos);
            int largest = pos;

            if(l < size && compare(heap[largest], heap[l])){
                largest = l;
            }
            if(r < size && compare(heap[largest], heap[r])){
                largest = r;
            }

            if(largest == pos) break;

            swap(heap[pos], heap[largest]);
            pos = largest;
        }

        return true;
    }

public:

    bool compare(pair<int,int> a, pair<int,int> b){
        if(a.first != b.first)
            return a.first < b.first;   // higher priority first
        return a.second > b.second;     // smaller ticketId first
    }
};



int main(){

    int currtime=0;
    bool tickprocess=false; // tickchalukina =0;

    MaxHeap waiting_ticket;   //pair =>ticketid,effective priority

    set<int>available_agents;
    map<int,int>busy_agents;   //=>map - key(agentid) ,value(ticktid)
    set<int>resolved_ticket;

    string cmd;
    while(cin>>cmd){

        if(cmd=="ADD_TICKET"){
            int ticketid,basepriority;
            cin>>ticketid>>basepriority;

            waiting_ticket.insert({basepriority,ticketid});

            if(tickprocess){
                while(!waiting_ticket.isempty() && !available_agents.empty()){
                    auto p = waiting_ticket.getmax();
                    int pri=p.first;
                    int tid=p.second;
                    waiting_ticket.deleteMax();

                    auto it =available_agents.begin();
                    int aid = *it;
                    available_agents.erase(it);

                    busy_agents[aid]=tid;
                }
            }
        }


        else if(cmd=="ADD_AGENT"){

            int agentid;
            cin>>agentid;

            available_agents.insert(agentid);

            if(tickprocess){
                while(!waiting_ticket.isempty() && !available_agents.empty()){
                    auto p = waiting_ticket.getmax();
                    int pri=p.first;
                    int tid=p.second;
                    waiting_ticket.deleteMax();

                    auto it =available_agents.begin();
                    int aid = *it;   // ticket id ber kore ;
                    available_agents.erase(it);

                    busy_agents[aid]=tid;
                }
            }
        }

        else if(cmd=="REMOVE_AGENT"){ // work only free agent ,

            int agentid;
            cin>>agentid;

            if(available_agents.count(agentid)){
                available_agents.erase(agentid);
            }
        }
        else if(cmd=="TICK"){
            currtime++;
            tickprocess=true;

            // FIX: dynamically increase waiting ticket priorities
            vector<pair<int,int>> tempTickets;

            while(!waiting_ticket.isempty()){

                auto p = waiting_ticket.getmax();
                waiting_ticket.deleteMax();

                int pri = p.first;
                int tid = p.second;

                tempTickets.push_back({pri + 1, tid});
            }

            for(auto &t : tempTickets){
                waiting_ticket.insert(t);
            }

            vector<int>freeagents;
            for(auto &p :busy_agents){
                resolved_ticket.insert(p.second);
                freeagents.push_back(p.first);
            }
            busy_agents.clear();

            for(int aid :freeagents){
                available_agents.insert(aid);
            }

            while(!waiting_ticket.isempty() && !available_agents.empty()){

                  auto p = waiting_ticket.getmax();
                    int pri=p.first;
                    int tid=p.second;
                    waiting_ticket.deleteMax();

                    auto it =available_agents.begin();
                    int aid = *it;
                    available_agents.erase(it);

                    busy_agents[aid]=tid;
            }
        }


        else if(cmd=="QUERY"){
            cout<<"Time: "<<currtime<<endl;

            MaxHeap temp = waiting_ticket;

            cout<<"Waiting: [";
            bool firstres=true;

            while(!temp.isempty()){
                auto p=temp.getmax();
                int pri=p.first;
                int tid=p.second;

                temp.deleteMax();
                if(!firstres)cout<<",";
                cout<<"("<<pri<<","<<tid<<")";
                firstres=false;
            }
            cout<<"]"<<endl;

            cout << "Busy Agents: [";
            bool first = true;
            for (auto& p : busy_agents) {
                if (!first) cout << ",";
                cout << "(" << p.first << "," << p.second << ")";
                first = false;
            }
            cout << "]" << endl;

            cout<<"Resolved: [";
             first=true;
            for(int rid:resolved_ticket){
                if(!first)cout<<",";

                cout<<rid;
                first=false;
            }
            cout<<"]"<<endl;
        }
    }
}