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
         string l_sInputName;
         cin >> l_sInputName;
         bool l_bResult = false;

         vector<string> l_vStops = l_mGlobalBus[l_sInputName];
         if(l_vStops.size())
         {
            for(auto& l_sStop : l_vStops)
            {
               
            }
         }


      }

   }
}