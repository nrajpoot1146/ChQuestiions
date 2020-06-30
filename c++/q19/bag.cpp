
void Bag::push_back(string str){
	items.push_back(str);
}

int Bag::size(){
	return this->items.size();
}

string Bag::at(int i){
	return this->items.at(i);
}

Bag Bag::bagUnionWith(Bag bag){
	Bag bag3;
	int i=0;
	
	while(i<this->items.size()){
		bag3.push_back(this->items.at(i));
		i++;
	}
	
	i=0;
	while(i<bag.size()){
		bag3.push_back(bag.at(i));
		i++;
	}
	
	return bag3;
}
