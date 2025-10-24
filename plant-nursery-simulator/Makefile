test: iterator_unit_test mediator_unit_test
	@echo "==== ALL PROJECT TESTS DONE ===="

mediator_colleague_test: 
	@echo "== Testing 'Colleague.cpp' =="
	@mkdir -p build
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/Colleague.cpp -o build/Colleague.o

mediator_customer_test:
	@echo "== Testing 'Customer.cpp' =="
	@mkdir -p build
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/Customer.cpp -o build/Customer.o

mediator_nursery_test:
	@echo "== Testing 'NurseryMediator.cpp' =="
	@mkdir -p build
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/NurseryMediator.cpp -o build/NurseryMediator.o

mediator_unit_test:
	@echo "== Building and Running 'mediator_test.cpp' (UNIT TEST) =="
	@mkdir -p build
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude \
		src/Colleague.cpp \
		src/Customer.cpp \
		src/NurseryMediator.cpp \
		tests/mediator_test.cpp \
		-o build/mediator_unit_test
	./build/mediator_unit_test

mediator_test: 
	@echo "==== TESTING MEDIATOR DESIGN ===="
	$(MAKE) mediator_colleague_test
	$(MAKE) mediator_customer_test
	$(MAKE) mediator_nursery_test
	$(MAKE) mediator_unit_test

iterator_unit_test:
	@echo "== Building and Running 'iterator_test.cpp' (UNIT TEST) =="
	@mkdir -p build
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude \
		tests/iterator_test.cpp \
		src/Inventory.cpp \
		src/InventoryCollection.cpp \
		src/InventoryIterator.cpp \
		src/ConcreteInventoryIterator.cpp \
		src/StockItem.cpp \
		src/PlantInstance.cpp \
		-o build/iterator_unit_test
	./build/iterator_unit_test


clean:
	@echo "==== CLEANING BUILD DIRECTORY ===="
	rm -rf build
