#include<bits/stdc++.h>
using namespace std;


vector<bool> present(10);


void print_array(vector<int> &v){

    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
}

void congrats(vector<int> &v){

    cout<<"congrats! The correct answer is :\n";
    print_array(v);
    exit(0);
}

void check_if_increased(vector<int> v,vector<int> &value_at_index,int index,int dollars,bool &increased){ //v is passed as copy, increased is passed by reference

        //swap all allowed indexes with the given index and see if there is any increase in dollars

            for(int i=0;i<v.size();i++){

                if(index==i||value_at_index[i]!=-1) //if value at index[i] is fixed, don't swap with it
                continue;

                swap(v[index],v[i]);
                print_array(v);
                int new_cents,new_dollars;
                cin>>new_cents>>new_dollars;

                if(new_dollars==v.size()){
                    congrats(v);
                }

                swap(v[index],v[i]);//swap back


                if(new_dollars>dollars){
                    increased = true;
                    return;
                }
            }
}


void play_game(int n){

    cout<<"Guess the n length array\n";

    int cents=-1,dollars=-1;

        for(int i=0;i<10;i++){ //change algo with combination of letters

            for(int j=0;j<n;j++)
                cout<<i<<" ";
            cout<<endl;
            cin>>cents>>dollars;

            if(dollars>0) {
                present[i]=1;
                if(n==1){
                    cout<<"Guess is correct\n";
                    cout<<i<<endl;
                    exit(0);
                }
            }
        }

        for(int i=0;i<10;i++)
            cout<<"digit "<<i<<" is "<<(present[i]==1?"present ":"absent ")<<"in the array"<<endl;

        dollars=-1;


        vector<int> v(n),value_at_index(n,-1); // value_at_index[i]=-1 means unknown value



            for(int tt=0;tt<n;tt++){
                //in every iteration at least 1(max 2) digit will be at its correct position


                cout<<"start of tt loop\n";

                if(dollars==-1){ //first guess
                int j=0;
                for(int i=0;i<10;i++)
                    if(present[i]==1)
                    {
                        v[j]=i;
                        j++;
                    }
                }

                print_array(v);
                cin>>cents>>dollars;

                cout<<"cents : "<<cents<<" Dollars: "<<dollars<<endl;




                // new index, which will be swapped with i
                    int cnt=0; //count of unfounded digits
                    int index=-1;

                    for(int j=0;j<n;j++){
                        if(value_at_index[j]==-1){
                            if(index==-1)
                            index = j;
                            cnt++;
                        }
                    }


                    if(cnt==0){
                        congrats(value_at_index);
                    }
                    else if(cnt==1){
                        //if only 1 index is remaining, fill it with the remaining present value
                        vector<int> digit_freq(10);

                        for(int ii=0;ii<10;ii++){
                            if(present[ii]==1)
                                digit_freq[ii]++;
                        }
                        for(int ii=0;ii<n;ii++){
                            if(value_at_index[ii]!=-1)
                                digit_freq[value_at_index[ii]]--;
                        }

                        int val=-1;
                        for(int ii=0;ii<10;ii++)
                        {
                            if(digit_freq[ii]>0){
                                val=ii;
                                break;
                            }
                        }
                        value_at_index[index] = val;
                        congrats(value_at_index);
                    }

                    cout<<"count remaining: "<<cnt<<endl;
                    cout<<"\ncurrent index is "<<index<<endl;


            //more than 1 positions remaining

            for(int i=0;i<n;i++){

                if(index==i||value_at_index[i]!=-1) //if value at index[i] is fixed, don't swap with it
                continue;


            //swap values at index and i
            swap(v[index],v[i]);
            print_array(v);
            int new_cents,new_dollars;
            cin>>new_cents>>new_dollars;

            //cout<<new_dollars<<" "<<n<<endl;

            if(new_dollars==n){
                congrats(v);
            }

            //5 conditions: -2, -1, 0, 1, 2

            // 0 condition, no change
            if(new_dollars==dollars){

                // none of 2 are at correct position
                swap(v[index],v[i]); //swap to original position
                //move to next i
                continue;
            }

            //rest conditions, at least one position will be known, break from loop
            if(new_dollars==dollars-2){

                cout<<"last 2 are at correct position"<<endl;
                swap(v[index],v[i]); //swap to original position
                value_at_index[index]=v[index];
                value_at_index[i] = v[i];
                cnt-=2;
                if(cnt==0)
                congrats(value_at_index);
            }

            else if((new_dollars==dollars-1)||(new_dollars==dollars+1)){
                //one of them is at correct position
                //find which one is at its correct position either v[index] or v[i]
                // swap v[index] with all non fixed position, if dollars increase in any then v[i] is true else v[index] is at its true position.


                bool increased=false;

                if(new_dollars==dollars-1){
                        swap(v[index],v[i]);
                check_if_increased(v,value_at_index,index,dollars,increased);
                }
                else {
                    check_if_increased(v,value_at_index,index,new_dollars,increased);
                }

                if(increased){
                    value_at_index[i]=v[i];
                }
                else value_at_index[index] = v[index];

            }
            else if(new_dollars==dollars+2){

                cout<<"now both are at the correct position"<<endl;
                value_at_index[i]=v[i];
                value_at_index[index]=v[index];

                cnt-=2;
                if(cnt==0)
                congrats(value_at_index);
            }
            else {
                cout<<"these error cases needs to be considered\n";
                exit(0);
            }

            cout<<"loop finishes\n";
            print_array(value_at_index);
            print_array(v);
            cout<<endl;
            break;
            }
        }
}



int main(){

    int n;
    cout<<"Enter the length of array\n";
    cin>>n;

    play_game(n);
}
