LINK_LIBRARIES(
	generate
	atomspace
	logger
)

# Run the tests in logical order, not alphabetical order.
ADD_CXXTEST(AggregationUTest)
