STATE_SRCS = src/SeedState.cpp src/GrowingState.cpp src/MatureState.cpp src/WitheringState.cpp src/DeadState.cpp
STATE_OBJS = $(STATE_SRCS:src/%.cpp=build/%.o)

test: iterator_unit_test mediator_unit_test command_unit_test builder_unit_test chain_of_responsibility_unit_test facade_unit_test adapter_unit_test greenhouse_iterator_unit_test plant_instance_unit_test plant_state_unit_test strategy_unit_test composite_unit_test observer_unit_test prototype_unit_test
	@echo "==== ALL PROJECT TESTS DONE ===="

clean:
	@echo "==== CLEANING BUILD DIRECTORY ===="
	rm -rf build

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
		src/GreenhouseComponent.cpp \
		src/Inventory.cpp \
		src/InventoryCollection.cpp \
		src/InventoryIterator.cpp \
		src/ConcreteInventoryIterator.cpp \
		src/StockItem.cpp \
		src/PlantInstance.cpp \
		src/Subject.cpp \
		$(STATE_SRCS) \
		src/Plant.cpp \
		-o build/iterator_unit_test
	./build/iterator_unit_test


builder_unit_test:
	@echo "== Building and Running 'builder_test.cpp' (UNIT TEST) =="
	@mkdir -p build
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude \
		tests/builder_test.cpp \
		src/GreenhouseComponent.cpp \
		src/Order.cpp \
		src/OrderBuilder.cpp \
		src/CustomOrderBuilder.cpp \
		src/OrderDirector.cpp \
		src/StockItem.cpp \
		src/PlantInstance.cpp \
		src/Subject.cpp \
		$(STATE_SRCS) \
		src/Plant.cpp \
		-o build/builder_unit_test
	./build/builder_unit_test

command:
	@mkdir -p build
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/PlantCommand.cpp    -o build/PlantCommand.o
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/WaterPlant.cpp       -o build/WaterPlant.o
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/FertilizePlant.cpp   -o build/FertilizePlant.o
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/GreenhouseComponent.cpp -o build/GreenhouseComponent.o
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/PlantInstance.cpp    -o build/PlantInstance.o
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/Subject.cpp          -o build/Subject.o
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/SeedState.cpp        -o build/SeedState.o
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/GrowingState.cpp     -o build/GrowingState.o
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/MatureState.cpp      -o build/MatureState.o
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/WitheringState.cpp   -o build/WitheringState.o
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/DeadState.cpp        -o build/DeadState.o
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/Plant.cpp            -o build/Plant.o

command_unit_test: command
	@echo "== Building and Running 'command_test.cpp' (UNIT TEST) =="
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude \
		build/PlantCommand.o \
		build/WaterPlant.o \
		build/FertilizePlant.o \
		build/PlantInstance.o \
		build/Subject.o \
		$(STATE_OBJS) \
		build/Plant.o \
		build/GreenhouseComponent.o \
		tests/command_test.cpp \
		-o build/command_unit_test
	./build/command_unit_test
chain_of_responsibility:
	@mkdir -p build
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/CareRequestHandler.cpp   -o build/CareRequestHandler.o
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/WateringHandler.cpp      -o build/WateringHandler.o
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/FertilizingHandler.cpp   -o build/FertilizingHandler.o
	# PlantInstance is the CoR receiver; reuse your existing implementation
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/PlantInstance.cpp        -o build/PlantInstance.o
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/Subject.cpp              -o build/Subject.o
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/SeedState.cpp            -o build/SeedState.o
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/GrowingState.cpp         -o build/GrowingState.o
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/MatureState.cpp          -o build/MatureState.o
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/WitheringState.cpp       -o build/WitheringState.o
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/DeadState.cpp            -o build/DeadState.o
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/Plant.cpp                -o build/Plant.o

chain_of_responsibility_unit_test: chain_of_responsibility
	@echo "== Building and Running 'chain_of_responsibility_test.cpp' (UNIT TEST) =="
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude \
		build/CareRequestHandler.o \
		build/WateringHandler.o \
		build/FertilizingHandler.o \
		build/PlantInstance.o \
		build/Subject.o \
		$(STATE_OBJS) \
		build/Plant.o \
		build/GreenhouseComponent.o \
		tests/chain_of_responsibility_test.cpp \
		-o build/cor_unit_test
	./build/cor_unit_test


facade_unit_test:
	@echo "== Building and Running 'facade_test.cpp' (UNIT TEST) =="
	@mkdir -p build
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude \
		tests/facade_test.cpp \
		src/SalesFacade.cpp \
		src/PaymentProcessor.cpp \
		src/Inventory.cpp \
		src/OrderBuilder.cpp \
		src/CustomOrderBuilder.cpp \
		src/Order.cpp \
		src/StockItem.cpp \
		src/PlantInstance.cpp \
		src/Subject.cpp \
		$(STATE_SRCS) \
		src/Plant.cpp \
		src/InventoryCollection.cpp \
		src/InventoryIterator.cpp \
		src/ConcreteInventoryIterator.cpp \
		build/GreenhouseComponent.o \
		-o build/facade_unit_test
	./build/facade_unit_test

adapter_unit_test:
	@echo "== Building and Running 'adapter_test.cpp' (UNIT TEST) =="
	@mkdir -p build
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude \
		tests/adapter_test.cpp \
		src/Inventory.cpp \
		src/FileAdapter.cpp \
		src/TXTAdapter.cpp \
		src/CSVAdapter.cpp \
		src/TXTReaderWriter.cpp \
		src/CSVReaderWriter.cpp \
		src/StockItem.cpp \
		src/PlantInstance.cpp \
		src/Subject.cpp \
		$(STATE_SRCS) \
		src/Plant.cpp \
		src/InventoryCollection.cpp \
		src/InventoryIterator.cpp \
		src/ConcreteInventoryIterator.cpp \
		src/GreenhouseBed.cpp \
		src/ConcreteGreenhouseIterator.cpp \
		src/PlantPrototypeRegistry.cpp \
		build/GreenhouseComponent.o \
		-o build/adapter_unit_test
	./build/adapter_unit_test

composite_unit_test:
	@echo "== Building and Running 'composite_test.cpp' (UNIT TEST) =="
	@mkdir -p build
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude \
		tests/composite_test.cpp \
		src/GreenhouseComponent.cpp \
		src/GreenhouseBed.cpp \
		src/ConcreteGreenhouseIterator.cpp \
		src/GreenhouseController.cpp \
		src/PlantInstance.cpp \
		src/Subject.cpp \
		$(STATE_SRCS) \
		src/Plant.cpp \
	-o build/composite_unit_test
	./build/composite_unit_test

prototype_unit_test:
	@echo "== Building and Running 'prototype_test.cpp' (UNIT TEST) =="
	@mkdir -p build
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude \
		tests/prototype_test.cpp \
		src/Plant.cpp \
		src/PlantPrototypeRegistry.cpp \
		-o build/prototype_unit_test
	./build/prototype_unit_test

greenhouse_iterator_unit_test:
	@echo "== Building and Running 'greenhouse_iterator_test.cpp' (UNIT TEST) =="
	@mkdir -p build
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude \
		tests/greenhouse_iterator_test.cpp \
		src/GreenhouseComponent.cpp \
		src/GreenhouseBed.cpp \
		src/ConcreteGreenhouseIterator.cpp \
		src/GreenhouseController.cpp \
		src/PlantInstance.cpp \
		src/Subject.cpp \
		$(STATE_SRCS) \
		src/Plant.cpp \
		-o build/greenhouse_iterator_unit_test
	./build/greenhouse_iterator_unit_test

plant_instance_unit_test:
	@echo "== Building and Running 'plant_instance_test.cpp' (UNIT TEST) =="
	@mkdir -p build
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude \
		tests/plant_instance_test.cpp \
		src/GreenhouseComponent.cpp \
		src/PlantInstance.cpp \
		src/Subject.cpp \
		$(STATE_SRCS) \
		src/Plant.cpp \
		-o build/plant_instance_unit_test
	./build/plant_instance_unit_test

plant_state_unit_test:
	@echo "== Building and Running 'plant_state_test.cpp' (UNIT TEST) =="
	@mkdir -p build
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude \
		tests/plant_state_test.cpp \
		src/GreenhouseComponent.cpp \
		src/PlantInstance.cpp \
		src/Subject.cpp \
		$(STATE_SRCS) \
		src/waterStrategy.cpp \
		src/FertilizeStrategy.cpp \
		src/Plant.cpp \
		-o build/plant_state_unit_test
	./build/plant_state_unit_test

strategy:
	@echo "== Compiling Strategy Pattern Source Files =="
	@mkdir -p build
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/waterStrategy.cpp        -o build/waterStrategy.o
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/FertilizeStrategy.cpp     -o build/FertilizeStrategy.o
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/FrequentWatering.cpp      -o build/FrequentWatering.o
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/SparseWatering.cpp        -o build/SparseWatering.o
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/SeasonalWatering.cpp      -o build/SeasonalWatering.o
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/LiquidFertilizer.cpp      -o build/LiquidFertilizer.o
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/SlowReleaseFertilizer.cpp -o build/SlowReleaseFertilizer.o
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/OrganicFertilizer.cpp     -o build/OrganicFertilizer.o
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/PlantInstance.cpp         -o build/PlantInstance.o
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/Subject.cpp               -o build/Subject.o
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/SeedState.cpp             -o build/SeedState.o
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/GrowingState.cpp          -o build/GrowingState.o
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/MatureState.cpp           -o build/MatureState.o
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/WitheringState.cpp        -o build/WitheringState.o
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/DeadState.cpp             -o build/DeadState.o
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/Plant.cpp                 -o build/Plant.o
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude -c src/GreenhouseComponent.cpp   -o build/GreenhouseComponent.o

strategy_unit_test: strategy
	@echo "== Building and Running 'strategy_test.cpp' (UNIT TEST) =="
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude \
		build/waterStrategy.o \
		build/FertilizeStrategy.o \
		build/FrequentWatering.o \
		build/SparseWatering.o \
		build/SeasonalWatering.o \
		build/LiquidFertilizer.o \
		build/SlowReleaseFertilizer.o \
		build/OrganicFertilizer.o \
		build/PlantInstance.o \
		build/Subject.o \
		$(STATE_OBJS) \
		build/Plant.o \
		build/GreenhouseComponent.o \
		tests/strategy_test.cpp \
		-o build/strategy_unit_test
	./build/strategy_unit_test

observer_unit_test:
	@echo "== Building and Running 'observer_test.cpp' (UNIT TEST) =="
	@mkdir -p build
	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude \
		tests/observer_test.cpp \
		src/GreenhouseComponent.cpp \
		src/PlantInstance.cpp \
		src/StockItem.cpp \
		src/Colleague.cpp \
		src/Staff.cpp \
		src/Subject.cpp \
		$(STATE_SRCS) \
		src/Plant.cpp \
		-o build/observer_unit_test
	./build/observer_unit_test
