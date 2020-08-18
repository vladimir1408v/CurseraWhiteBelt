#include <string>
#include <iostream>
#include <vector>

using namespace std;


void Next_Month(int& in_iMonth, const vector<int>& in_vMonths, vector<vector<string>>& in_vTsks) {
   in_iMonth++;
   if (in_iMonth > 11)in_iMonth = 0;
   vector<vector<string>> NewMonth = in_vTsks;
   int a = in_vTsks.size();
   int b = in_vMonths[in_iMonth];
   in_vTsks.resize(b);
   const int e = b - 1;
   if (a > b) {
      for (b; a > b; b++) {
         in_vTsks[e].insert(end(in_vTsks[e]), begin(NewMonth[b]), end(NewMonth[b]));
      }
   }
   NewMonth.clear();
}

void Show_Tasks(int day, const vector<vector<string>>& tsks)
{
   cout << tsks[day - 1].size();
   if (tsks[day - 1].size() == 0)
   {
      cout << endl; return;
   }
   for (auto i : tsks[day - 1])
   {
      cout << " " << i;
   }
   cout << endl;
}

int main()
{
   int l_iCount;
   cin >> l_iCount;

   vector<int> days_in_month = { 31,28,31,30,31,30,31,31,30,31,30,31 };
   vector<vector<string>> l_vTasks;

   int index_of_month = 0;
   l_vTasks.resize(days_in_month[index_of_month], {});
   for (int i = 0; l_iCount > i; i++) {
      string l_sComand;
      int d;
      string t;
      cin >> l_sComand;
      if (l_sComand == "NEXT") {
         Next_Month(index_of_month, days_in_month, l_vTasks);
      }
      else if (l_sComand == "DUMP") {
         cin >> d;
         Show_Tasks(d, l_vTasks);
      }
      else if (l_sComand == "ADD") {
         cin >> d >> t;
         l_vTasks[d - 1].push_back(t);
      }
   }
   return 0;
}