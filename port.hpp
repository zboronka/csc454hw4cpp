#ifndef PORT_HPP
#define PORT_HPP

template <class T>
class Port {
	private:
		T payload;
		bool open = false;
	public:
		void set(T t) { payload = t; open = true; }
		T get() { if(open) { open = false; return payload; } throw "PortNotOpenException"; }
		bool available() { return open; }
};

#endif
