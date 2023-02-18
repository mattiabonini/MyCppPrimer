#include <iostream>
#include <set>
#include <string>

using std::string;
using std::set;

class Message;

class Folder {
	friend class Message;
	
	public:
	Folder() = default;
	~Folder();

	void add_msg(Message *m);
	void remove_msg(Message *m);
	void print() const; 
	
	private:
	set<Message*> messages;
};

class Message {
	friend class Folder;
	friend void swap(Message &lhs, Message &rhs);
	
	public:
	Message(string contents_ = "") : contents(contents_) {}
	Message(Message &m) : contents(m.contents), folders(m.folders) {
		add_to_folders(*this);
	}
	
	Message& operator=(Message &rhs) {
		remove_from_folders(*this);
		contents = rhs.contents;
		folders = rhs.folders;
		add_to_folders(*this);
		return *this;
	}
	
	~Message() { remove_from_folders(*this); }
	
	void save(Folder &f) {
		add_folder(&f);
		f.add_msg(this);
	}
	
	void remove(Folder &f) {
		remove_folder(&f);
		f.remove_msg(this);
	}
	
	void add_folder(Folder *f) { folders.insert(f); }
	void remove_folder(Folder *f) { folders.erase(f); }
	
	void print() {
		std::cout << contents << std::endl;
	}
		
	private:
	string contents;
	set<Folder*> folders;
	
	void add_to_folders(Message &m) {
		for(auto &f : folders) f->add_msg(&m);
	}
	
	void remove_from_folders(Message &m) {
		for(auto &f : folders) f->remove_msg(&m);
	}
};

void swap(Message &lhs, Message &rhs) {
	// Removing messages from the folders
	for(auto &f : lhs.folders) f->remove_msg(&lhs);
	for(auto &f : rhs.folders) f->remove_msg(&rhs);
	
	// Swapping data
	using std::swap;
	swap(lhs.contents, rhs.contents);
	swap(lhs.folders, rhs.folders);
	
	// Adding messages to folders
	for(auto &f : lhs.folders) f->add_msg(&lhs);
	for(auto &f : rhs.folders) f->add_msg(&rhs);
}

void Folder::add_msg(Message *m) { messages.insert(m); }
void Folder::remove_msg(Message *m) { messages.erase(m); }
void Folder::print() const {
	for(const auto &m : messages) m->print();
}
Folder::~Folder() {
	for(auto &m : messages) m->remove_folder(this);
}


int main() {
	Message m1("Hello"), m2("Ciao"), m3("How are you?"), m4("Fine thanks!"), m5("Come stai?"), m6("Bene grazie!");
	Folder ita, eng, saluti;
	m1.save(eng);
	m2.save(ita);
	m3.save(eng);
	m4.save(eng);
	m5.save(ita);
	m6.save(ita);
	m1.save(saluti);
	m2.save(saluti);
	
	std::cout << "Italian messages" << std::endl;
	ita.print();
	std::cout << "English messages" << std::endl;
	eng.print();
	std::cout << "Cheering messages" << std::endl;
	saluti.print();
	
	return 0;
}
