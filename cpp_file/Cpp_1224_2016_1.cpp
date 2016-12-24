#include <iostream>
#include <string>
#include <time>
#include <windows>
using namespace std;

/* クラス 宣言だけ */
class Cara
{
	private:
		
	public:
		string name;
		int CA[4];
		Cara( string s );
		void list();
		void out_data();
};

/* 定義は外 */
Cara::Cara( string s ):name( s ) {}

void Cara::list()
{
	srand( (unsigned)time(NULL) );
	CA[0] = 1;
	CA[1] = rand() % 10 + 1;
	CA[2] = rand() % 10 + 1;
	CA[3] = rand() % 10 + 1;
}

void Cara::out_data( )
{
	cout << "NE:" << name << endl;
	cout << "LE:" << CA[0] << endl;
	cout << "HP:" << CA[1] << endl;
	cout << "AT:" << CA[2] << endl;
	cout << "DE:" << CA[3] << endl;
}

/* main */
int main()
{
	string in_name;
	
	cout << "入力：";
	cin >> in_name;
	
	Cara one( in_name );
	Cara two( "てき" );
	
	one.list();
	Sleep( 1000 );
	two.list();
	
	one.out_data( );
	two.out_data( );
	
	for( int i = 0; i < 4; i++ ) {
		cout << one.CA[i] << endl;
	}
	for( int i = 0; i < 4; i++ ) {
		cout << two.CA[i] << endl;
	}
	
	return 0;
}