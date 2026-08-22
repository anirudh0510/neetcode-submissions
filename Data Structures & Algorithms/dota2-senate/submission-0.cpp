class Solution {
public:

    bool removeSenator(string &senate, char ch, int index) {
        bool checkRemovalLeftSide = false;

        while (true) {

            if (index == 0) {
                checkRemovalLeftSide = true;
            }

            if (senate[index] == ch) {
                senate.erase(senate.begin() + index);
                break;
            }

            index = (index + 1) % senate.size();
        }

        return checkRemovalLeftSide;
    }

    string predictPartyVictory(string senate) {

        int R_Count = count(senate.begin(), senate.end(), 'R');
        int D_Count = senate.length() - R_Count;

        int index = 0;

        while (R_Count > 0 && D_Count > 0) {

            if (senate[index] == 'R') {

                bool checkRemovalLeftSide =
                    removeSenator(senate, 'D', (index + 1) % senate.size());

                D_Count--;

                if (checkRemovalLeftSide) {
                    index--;
                }
            }
            else {

                bool checkRemovalLeftSide =
                    removeSenator(senate, 'R', (index + 1) % senate.size());

                R_Count--;

                if (checkRemovalLeftSide) {
                    index--;
                }
            }

            index = (index + 1) % senate.size();
        }

        return R_Count == 0 ? "Dire" : "Radiant";
    }
};