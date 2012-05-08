#ifndef VECTOR_REF_H
#define VECTOR_REF_H
template<class T> class vector_ref {
public:
    vector_ref() {
	}
    vector_ref(T& a) { 
		push_back(a); 
	}
    ~vector_ref() { 
		for (int i=0; i<owned.size(); ++i) {
			delete owned[i]; 
		}
	}
    void push_back(T& s) { v.push_back(&s); }
    void push_back(T* p) { v.push_back(p); owned.push_back(p); }
    T&       operator[](int i)       { return *v[i]; }
    const T& operator[](int i) const { return *v[i]; }
    int size() const { return v.size(); }
private:
    vector<T*> v;
    vector<T*> owned;
};
#endif
