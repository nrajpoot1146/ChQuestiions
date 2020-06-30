#ifndef diy

#define diy
template <typename T>
class DiyVector{
    public:
        DiyVector():_size(0){
            s_size=_size;
            p=NULL;
        }
        ~DiyVector(){};

        T& at(unsigned int index) const{
            if(index<_size)
                return p[index];
            OutOfRange ot;
            throw ot;
        }
        // item at index
        // throws OutOfRange

        unsigned int size() const{
            return _size;
        }
        // number of items in the vector

        void pushBack(const T& item){
            if(s_size>_size){
                p[_size]=item;
                _size++;
                return;
            }
            T *temp = new T[_size+1];
            for(int i=0;i<_size;i++){
                temp[i] = p[i];
            }
            temp[_size]=item;
            delete p;
            p=temp;
            _size++;
            s_size=_size;
        }
        // append item at the end of vector

        void popBack(){
            if(_size==0){
                OutOfRange ot;
                throw ot;
            }
            _size--;
        }
        // remove item at the end of vector
        // throws OutOfRange

        void erase(unsigned int index){
            if(index>=_size){
                OutOfRange ot;
                throw ot;
            }
            for(int i=index;i<_size-1;i++){
                p[i]=p[i+1];
            }
            _size--;
        }
        // remove element at index
        // throws OutOfRange

        void insert(unsigned int index, const T& item){
            if(item<0){
                OutOfRange ot;
                throw ot;
            }
            if(s_size>_size){
                for(int i=_size;i>index;i--){
                    p[i]=p[i-1];
                }
                p[index]=item;
                _size++;
                return;
            }
            int t_size=_size+1;
            T *temp = new T[t_size];
            for(int i=0,j=0;i<t_size;i++,j++){
                if(i==index){
                    temp[i]=item;
                    j--;
                    continue;
                }
                temp[i] = p[j];
            }
            delete p;
            p=temp;
            _size=t_size;
            s_size=_size;
        }
        // insert item before element at index, with:
        // 0 <= index <= size()
        // throws OutOfRange

        class OutOfRange{};

    private:
        T *p;
        int _size;
        int s_size;
        // your implementation goes here!
};
#endif // diy
