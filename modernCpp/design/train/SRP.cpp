#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;


class Bad_Journal {
public:
	Bad_Journal ( const string & title ) : m_title ( title ) {
	}
	void add ( const string & entry ) {
		m_entries.push_back ( entry ) ;
	}
	// bad journal
	// because it is not responsibility of journal to save itself
	// today, it could be file, tomorrow, it could be middleware or something
	// each time the journal persistence target changes, you will have to touch Bad_Journal 
	void save ( const string & filename ) {
	    ofstream	fileObj ( filename );
		for_each ( m_entries.begin(), m_entries.end(),
			[&](string value) { fileObj << value << endl; } );
	}
private:
	string				m_title;
	vector<string>		m_entries;
};

class Good_Journal {
public:
	Good_Journal ( const string & title ) : m_title ( title ) {
	}
	void add ( const string & entry ) {
		m_entries.push_back ( entry ) ;
	}
private:
	string				m_title;
	vector<string>		m_entries;
	friend class PersistJournal ;
};

class PersistJournal {
public:
	static void save ( const Good_Journal &j, const string & filename ) {
	    ofstream	fileObj ( filename );
		for_each ( j.m_entries.begin(), j.m_entries.end(),
			[&](string value) { fileObj << value << endl; } );
	}
};

void test_Bad_Journal ( ) {
	Bad_Journal bjObj ( "bad_Journal" );
	bjObj.add ( "Entry_1" );
	bjObj.add ( "Entry_2" );
	bjObj.add ( "Entry_3" );
	bjObj.save ( "badJournal.txt" );
}
void test_Good_Journal ( ) {
	Good_Journal bjObj ( "Goodd_Journal" );
	bjObj.add ( "Entry_1" );
	bjObj.add ( "Entry_2" );
	bjObj.add ( "Entry_3" );
	PersistJournal::save ( bjObj, "GoodJournal.txt" );
}

int main ( int argc, char** argv ) {
    test_Bad_Journal ();
	test_Good_Journal ();
    return 0;
}


