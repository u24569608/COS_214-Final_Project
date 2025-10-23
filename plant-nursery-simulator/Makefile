mediator_colleague_test: 
	@echo "== Testing 'Colleague.cpp' =="
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/Colleague.cpp -o build/Colleague.o

mediator_customer_test:
	@echo "== Testing 'Customer.cpp' =="
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/Customer.cpp -o build/Customer.o

mediator_nursery_test:
	@echo "== Testing 'NurseryMediator.cpp' =="
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/NurseryMediator.cpp -o build/NurseryMediator.o

mediator_test: 
	@echo "==== TESTING MEDIATOR DESIGN ===="
	$(MAKE) mediator_colleague_test
	$(MAKE) mediator_customer_test
	$(MAKE) mediator_nursery_test

clean:
	rm -rf build/*.o
	@echo "==== BUILD DIRECTORY CLEANED ===="