class Students{
	long id;
	string name;
	public:
		Students(long id, string name){
			this->id = id;
			this->name = name;
		}
		
		long getId(){
			return this->id;
		}
		
		string getName(){
			return this->name;
		}
};
