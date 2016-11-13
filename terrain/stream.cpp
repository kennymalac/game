using namespace std;

struct Streamable {
  int age_;
  string name_;};

ostream& operator<<(ostream& sm, const Streamable& s) {
  sm << "My name is " << d.name_ << " and my age is " << d.age_ << endl;
  return sm;}

istream& operator>>(istream& sm, Streamable& s) {
  sm >> s.age_;
  sm >> s.name_;
  return sm;}

int main() {
  Streamable s{2, "Bob"}; //C++11 universal initialization
  cout << s;

  // IO operation:
  // 1. formating data -- stream
  // 2. communicating data to external devices -- held in a streambuffer

  cin >> s;
  cout << d;

  // cout's internal buffer reference
  cout << 34;
  streambuf* pbuf = cout.rdbuf();

  ostream myCout(pbuf);
  myCout << 34; // 34 to stdout

  myCout.setf(ios::showpos);
  myCout.width(20);
  myCout << 12 << endl; //      +12
  cout << 12 << endl; //         12

  ofstream of("MyLog.txt");
  streambuf* origBuf = cout.rdbuf();
  cout.rdbuf(of.rdbuf());
  cout << "Hello" << endl; // MyLog.txt has "Hello"
  //Redirecting

  cout.rdbuf(origBuf);

  cout << "Goodbye" << endl; //stdout: Goodbye

  // Stream buffer iterator
  istreambuf_iterator<char> i(cin);
  ostreambuf_iterator<char> o(cout);
  while (*i != 'x') {
    *o = *i;
    ++o;
    ++i;}

  // copy the iterator
  // this iterator is a pointer to the start of the char iterator
  copy(istreambuf_iterator<char>(cin), istreambuf_iterator<char>(), ostreambuf_iterator<char>(cout));}

ostream& endl(ostream& sm) { // Manipulator - a function that manipulates a string
  // the standard library documents a lot of manipulators
  sm.put('\n');
  sm.flush();
  return sm;}

// pointer of a function that points to endl
// template overriding at its finest
ostream& ostream::operator<<(ostream& (*func)(ostream&)) {
  return (*func)(*this);}

int main() {
  cout << "hello" << endl;

  couts << ends; // '\0'
  cout << flush;
  cin >> ws; // read and discard white spaces

  cout << setw(8) << left << setfill('_') << 99 << endl; //99________
  cout << hex << showbase << 14; // 0xe
  // look up more online (<include ios> docs, manipulators section in Input/Output subheading)
  }

