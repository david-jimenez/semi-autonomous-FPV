all: mavlink_control

mavlink_control: git_submodule mavlink_control.cpp
	g++ -I mavlink/include/mavlink/v1.0 main.cpp mavlink_control.cpp serial_port.cpp autopilot_interface.cpp -o test -lpthread

git_submodule:
	git submodule update --init --recursive

clean:
	 rm -rf *o mavlink_control
