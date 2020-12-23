#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

bool GetBusIsStop(vector<string>& in_vBussNames, map <string, vector<string>>& in_mBus, string& in_sName)
{
   bool l_bResult = false;
   for(auto& l_sName : in_mBus)
   {
      for(auto& l_sStop : l_sName.second)
      {
         if(in_sName == l_sStop)
         {
            in_vBussNames.push_back(l_sName.first);
            l_bResult = true;
            break;
         }
      }
   }
   return l_bResult;
}

int main()
{
   int l_iComandCount = 0;
   cin >> l_iComandCount;

   map <string, vector<string>> l_mGlobalBus;

   vector<string> comnd = {"NEW_BUS", "36", "A", "B", "C", "NEW_BUS", "47", "G", "H", "A", "B", ""};

   while(l_iComandCount--)
   {
      string l_sComand;
      cin >> l_sComand;

      if(l_sComand == "NEW_BUS")
      {
         string l_sName;
         cin >> l_sName;

         int l_iStop_count = 0;
         cin >> l_iStop_count;
         vector<string> l_vStopNames;
         while(l_iStop_count--)
         {
            string l_sStopName;
            cin >> l_sStopName;
            l_vStopNames.push_back(l_sStopName);
         }
         l_mGlobalBus[l_sName] = l_vStopNames;
      }

      if(l_sComand == "BUSES_FOR_STOP")
      {
         string l_sInputName;
         cin >> l_sInputName;

         vector<string> l_vBusNames;
         if(GetBusIsStop(l_vBusNames, l_mGlobalBus, l_sInputName))
         {
            for(auto& l_sStop : l_vBusNames)
               cout << l_sStop;
         } else
            cout << "No stop";
         cout << endl;
      }

      if(l_sComand == "STOPS_FOR_BUS")
      {
         string Bus;
         cin >> Bus;
         vector<string> temp_stops = l_mGlobalBus[Bus];
         map<string, vector<string>> result;
         for(auto stop_start : temp_stops)
         {
            for(auto stop : l_mGlobalBus)
            {
               for(auto stp : stop.second)
               {
                  result[stop_start];
                  if(stop_start == stp && Bus != stop.first)
                  {
                     result[stop_start].push_back(stop.first);
                  }
               }
            }
         }
         for(auto item : result)
         {
            std::cout << item.first+":";
            for(auto item2 : item.second)
            {
               std::cout << item2 + " ";
            }
            if(item.second.empty())
            {
               std::cout << " no onterchange";
            }
            std::cout << endl;
         }
      }

   }
}