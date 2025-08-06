# Include GoF++ headers and NTest (adjust path if NTest is external)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/vendor/NTest/include
    ${CMAKE_SOURCE_DIR}/vendor/NTest/vendor/NCLI/include
    # Add NCLI path if Colors.h is needed
)

# CREATIONAL TESTS
add_executable(test_singleton creational/test_singleton.cpp)
add_test(NAME TestSingleton COMMAND test_singleton)

add_executable(test_factory creational/test_factory.cpp)
add_test(NAME TestFactory COMMAND test_factory)

add_executable(test_abstract_factory creational/test_abstract_factory.cpp)
add_test(NAME TestAbstractFactory COMMAND test_abstract_factory)

add_executable(test_builder creational/test_builder.cpp)
add_test(NAME TestBuilder COMMAND test_builder)

add_executable(test_prototype creational/test_prototype.cpp)
add_test(NAME TestPrototype COMMAND test_prototype)


# BEHAVIORAL TESTS
add_executable(test_observer behavioral/test_observer.cpp)
add_test(NAME TestObserver COMMAND test_observer)

add_executable(test_state behavioral/test_state.cpp)
add_test(NAME TestState COMMAND test_state)

add_executable(test_command behavioral/test_command.cpp)
add_test(NAME TestCommand COMMAND test_command)

add_executable(test_chain_of_responsibility behavioral/test_chain_of_responsibility.cpp)
add_test(NAME TestChainOfResponsibility COMMAND test_chain_of_responsibility)

add_executable(test_strategy behavioral/test_strategy.cpp)
add_test(NAME TestStrategy COMMAND test_strategy)

add_executable(test_template_method behavioral/test_template_method.cpp)
add_test(NAME TestTemplateMethod COMMAND test_template_method)

add_executable(test_iterator behavioral/test_iterator.cpp)
add_test(NAME TestIterator COMMAND test_iterator)

add_executable(test_memento behavioral/test_memento.cpp)
add_test(NAME TestMemento COMMAND test_memento)

add_executable(test_interpreter behavioral/test_interpreter.cpp)
add_test(NAME TestInterpreter COMMAND test_interpreter)

add_executable(test_visitor behavioral/test_visitor.cpp)
add_test(NAME TestVisitor COMMAND test_visitor)


# Structural tests
add_executable(test_composite structural/test_composite.cpp)
add_test(NAME TestComposite COMMAND test_composite)

add_executable(test_bridge structural/test_bridge.cpp)
add_test(NAME TestBridge COMMAND test_bridge)

add_executable(test_mediator structural/test_mediator.cpp)
add_test(NAME TestMediator COMMAND test_mediator)

add_executable(test_adapter structural/test_adapter.cpp)
add_test(NAME TestAdapter COMMAND test_adapter)

add_executable(test_decorator structural/test_decorator.cpp)
add_test(NAME TestDecorator COMMAND test_decorator)

add_executable(test_facade structural/test_facade.cpp)
add_test(NAME TestFacade COMMAND test_facade)

add_executable(test_flyweight structural/test_flyweight.cpp)
add_test(NAME TestFlyweight COMMAND test_flyweight)

add_executable(test_proxy structural/test_proxy.cpp)
add_test(NAME TestProxy COMMAND test_proxy)
