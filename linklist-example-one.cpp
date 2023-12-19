#include <iostream>
using namespace std;
template<typename T> class sNode {
public:
	T data;
	sNode* next;
};

template<typename T> class singlyList {
private:
	int n;
	sNode<T> *head;
public:
	singlyList() {
		head = NULL;
		n = 0;
	}
	
	bool isEmpty() {
		return head == NULL;
	}
	int getSize() const {
		return n;
	}

	void addFont(const T& item) {
		sNode <T>* m = new sNode<T>;
		m->next = NULL;
		m->data = item;
		if (isEmpty()) {
			head =m ;
			n++;
			return;
		}
		else {
			m->next = head;
			head = m;
			n++;
			return;
		}
	}

	void displayList() const {
		sNode<T>* p = head;
		while (p != NULL) {
			cout << p->data << "\t";
			p = p->next;
		}
	}

	T getFront(){
		return head->data;
	}

	T getBack() {
		sNode<T>* p = head;
		while (p != NULL && p->next != NULL) {
			p = p->next;
			
		}
		return p->data;
	}

	void addBack(const T& item) {
		sNode <T>* m = new sNode<T>;
		m->next = NULL;
		m->data = item;
		if (isEmpty()) {
			addFont(item);
		}
		else {
			sNode<T>* p = head;
			while (p != NULL && p->next != NULL) {
				p = p->next;

			}
			p->next = m;
			n++;
		}

	}
    
	void addBackWithCon(const T& item) {
		if(item>=0&&item<=110){
		
			sNode <T>* m = new sNode<T>;
			m->next = NULL;
			m->data = item;
			if (isEmpty()) {
				addFont(item);
			}
			else {
				sNode<T>* p = head;
				while (p != NULL && p->next != NULL) {
					p = p->next;

				}
				p->next = m;
				n++;
			}
		}
		else {
			cout << "out of the range" << endl;
		}


	}

	bool removeFont() {
		if (isEmpty()) {
			return false;
		}

		sNode<T>* old = head;
		head = head->next;
		old->next = NULL;
		delete old;
		n--;
		return true;
	}

	bool removeBack() {
		if (isEmpty()) {
			return false;
		}

		if (n == 1) {
			delete head;
			head = NULL;
			n--;
			return true;
		}

		sNode<T>* p = head;
		sNode<T>* prev = NULL;
		while (p->next != NULL) {
			prev = p;
			p = p->next;
		}

		prev->next = NULL;
		delete p;
		n--;
		return true;
	}

    bool remove(const T& item) {
		sNode<T>* p = find(item);
		if (!p)return false;
		if (p == head) {
			removeFont();
		}
		if (p->next == NULL) {
			removeBack();
		}
		else {
			sNode<T>* q = head;
			while (q->next!=p) {
				q = q->next;

			}
			q->next = p->next;
			p->next = NULL;
			delete p;
			n--;
		}
		return true;
	}

	bool removeAfter(sNode<T>& ptr) {
		if (isEmpty || !ptr || !ptr->next) {
			return false;
		}

		sNode<T>* q = ptr->next;
		ptr->next = q->next;
		delete q;
		n--;
	}

	void removeAll() {
		sNode<T>* p = head;
		while (p) {
			removeFont();
			p = head;

		}
		head = NULL;
	}

	void insertAfter(sNode<T>* p, const T& item) {

		sNode<T>* m = new sNode<T>;
		m->data = item;
		while (p!=NULL)
		{
			m->next = p->next;
		}
		
		p->next = m;
	}

	void insertBack(sNode<T>* p, const T& item) {
		sNode<T>* m = new sNode<T>;
		m->data = item;
		sNode<T>* q = head;
		m->next = p;
		while (q->next!=p) {
			q = q->next;
		}
		q->next = m;
	}

	sNode<T>* find(const T& item) {
		if (isEmpty()) {
			return NULL;
        }

		sNode<T>* p = head;
		while (p && p->data != item) {
			p = p->next;
		}
		return p;
	}

	void swapNode(sNode <T>* p1, sNode <T>* p2) {
		sNode <T>* z = p2->next;
		sNode <T>* q = head;
		while (q->next != p1) {
			q = q->next;
		}
		q->next = p2;
		p2->next = p1;
		p1->next = z;
	}

	void append(const  singlyList <T>& obj) {
		sNode<T>p = this->head;
		while (p != NULL && p->next != NULL) {
			p = p->next;

		}
		if (!p) {
			return;
		}
		p->next = obj.head;
		this->n += obj.n;

	}
		
	singlyList(const singlyList<T>& M) {
		sNode<T>* p = M.head;
		while (p != NULL) {
			this->addBack(p->data);
			p = p->next;
     
		}

	}

	singlyList<T>& operator=(const singlyList<T>& M) {
		if (this != &M) {
			this->removeAll();
		}
		sNode<T>* p = M.head;
		while (p != NULL) {
			this->addBack(p->data);
			p = p->next;
		}
		return *this;
		
	}

	double getSumOfNodes() {
		sNode<T>* p = head;
		T sum = 0;
		while (p!=NULL)
		{
			sum += p->data;
			p = p->next;
		}
		return sum;
	}

	double avgOfNode() {
		sNode<T>* p = head;
		double sum = 0;
		double avg;
		while (p != NULL)
		{
			sum += p->data;
			p = p->next;
		}
		avg = sum / n;
		return avg;
	}

	T maxValueInList() {
		T max = head->next->data;
		sNode<T>* p = head->next;
		while (p != NULL)
		{
			if (max < p->data) {
				max = p->data;
			}
			p = p->next;
		}
		return max;
	}

	T minValueInList() {
		T min = head->next->data;
		sNode<T>* p = head->next;
		while (p != NULL)
		{
			if (min > p->data) {
				min = p->data;
			}
			p = p->next;
		}
		return min;
	}
	
	void DeleteGT() {
		sNode<T>* p = head;
		
		while (p != NULL)
		{
			if (p->data > 80) {
				p->next = NULL;
				delete p;
			}
			p = p->next;
		}
	}

	~singlyList() {
		while (!isEmpty()) {
			removeFont();
		}
		head = NULL;
		n = 0;
	}

};

int main()
{

	singlyList <int> obj1;
	singlyList <int> obj2;

	//cout << "the size of linkedlist is :" << obj.getSize() << endl;
	obj1.addBack(20);
	//obj.displayList();
	//cout << "the size of linkedlist is :" << obj.getSize() << endl;
	
	obj1.addBack(30);
	//cout << "the size of linkedlist is :" << obj.getSize() << endl;
	obj1.addBack(40);
	//cout << "the size of linkedlist is :" << obj.getSize() << endl;
	obj1.addBack(50);
    //	cout << "the size of linkedlist is :" << obj.getSize() << endl;
    obj1.displayList();
	cout << obj1.getSumOfNodes() << endl;
	//cout << endl;
	//cout << "the size of linkedlist is :" << obj.getSize() << endl;
	
	//cout << "the first number in linkedlist is : " << obj.getFront() << endl << "the last number in linkedlist is : " << obj.getBack() << endl;
	
	/*cout << "the linked list after delete the frist element is : ";
	obj.displayList();
	cout << endl;
	cout << "the size of linkedlist is :" << obj.getSize() << endl;*/
	//if (obj1.removeBack()) {
		//cout << "one";
	//}
	//cout << endl;
	//obj1.displayList();
	//cout << endl;

	//obj1.removeAll();
//	if (obj1.isEmpty()) {
	//	cout << "the list was deleted " << endl;
//	}
	//cout << "the size of linkedlist is :" << obj1.getSize() << endl;
	//obj2 = obj1;

	//obj2.displayList();
	cout << "the size of scound linkedlist is :" << obj2.getSize() << endl;







}

