#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <vector>
using namespace std;

class Pwdg{
public:
    void SetLength(int PwdLength);
    void SetCharVector(vector<char> c);
    void getPWD()const;

protected:
    int length;
    vector<char> characters;
    int i;


};

void Pwdg::SetLength(int PwdLength){
    length=PwdLength;
    return;
};

void Pwdg::SetCharVector(vector<char> c){
    characters=c;
    return;

};

void Pwdg::getPWD() const{
    int i=0;
    char password[length];
    srand(time(0));
    for(i=0;i<length; i++){
		password[i]=characters.at(rand()%73);
    }
    for(i=0;i<length;i++){
		cout<<password[i];
	}
	return;
};

class Strong_pwdg : public Pwdg{
	public: 
		void SetLength(int PwdLength){
			length=PwdLength;
			return;
		};
		void SetCharVector(vector<char> c){
			characters=c;
			return;
		};
		void getStrongPWD() const;
		
	private:
		vector<char> strong;
		
};



void Strong_pwdg::getStrongPWD() const{
		
		char password[length];
		int i;
		int boolean=1;
		
		int rand1;
		int rand2;
		int rand3;
		int rand4;
		
		while(boolean==1){
		srand(time(0));
		rand1=rand()%length;
		rand2=rand()%length;
		rand3=rand()%length;
		rand4=rand()%length;
		
		if(rand1==rand2){
			continue;
		}
		else if(rand1==rand3){
			continue;
		} 
		else if(rand1==rand4){
			continue;
		}
		else if(rand2==rand3){
			continue;
		}
		else if(rand2==rand4){
			continue;
		}
		else if(rand3==rand4){
			continue;
		}
		else{
			boolean=0;
		}
		
		}
		vector<char> strong(4);
		vector<char> nums={'0','1','2','3','4','5','6','7','8','9'};
		vector<char> lower={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
		vector<char> upper={'A', 'B','C','D','E', 'F','G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V','W', 'X', 'Y', 'Z'};
		vector<char> symbols={'!', '@', '#', '$', '%', '^', '&', '*', '+', '-', '='};
	
		srand(time(0));
	
		strong.at(0)=nums.at(rand()%9);
		strong.at(1)=symbols.at(rand()%11);
		strong.at(2)=upper.at(rand()%26);
		strong.at(3)=lower.at(rand()%26);
		cout<<"Four mandatory random chars:";
		for(i=0;i<4;i++){
			cout<<strong.at(i)<<" ";
		}	
		cout<<endl;
		password[rand1]=strong.at(0);
		password[rand2]=strong.at(1);
		password[rand3]=strong.at(2);
		password[rand4]=strong.at(3);
	
	
	for(i=0;i<length;i++){
		if((i==rand1) || (i==rand2) || (i==rand3) || (i==rand4)){
			continue;
		}
		else{
			password[i]=characters.at(rand()%73);
		}
	}
	cout<<"Password: ";
	for(i=0;i<length;i++){
		cout<<password[i];
	}
	return;
};




int main(){
	
	
	Pwdg regPassword;
	Strong_pwdg strongPassword;
	
	char decision;
	int userLength;
	int boolean=1;
	
	
	
	vector<char> everything={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h'
    ,'i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A', 'B','C','D',
    'E', 'F','G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
    'W', 'X', 'Y', 'Z', '!', '@', '#', '$', '%', '^', '&', '*', '+', '-', '='};

	
	while(boolean==1){
		cout<<"Enter a length: ";
		cin>>userLength;
		cout<<endl;
		if(userLength>=8){
			boolean=0;
		}
		else{
			continue;
		}
	}
	cout<<"Want a strong password? (Y/N)";
	cin>>decision;
	cout<<endl;
	
	if(decision=='Y'){
		strongPassword.SetCharVector(everything);
		strongPassword.SetLength(userLength); 
		strongPassword.getStrongPWD();
	}
	else if(decision=='N'){
		regPassword.SetCharVector(everything);
		regPassword.SetLength(userLength);
		cout<<"Password: ";
		regPassword.getPWD();
	}
		
	return 0;
}
	
		