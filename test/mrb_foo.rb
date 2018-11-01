##
## Foo Test
##

assert("Foo#hello") do
  t = Foo.new "hello"
  assert_equal("hello", t.hello)
end

assert("Foo#bye") do
  t = Foo.new "hello"
  assert_equal("hello bye", t.bye)
end

assert("Foo.hi") do
  assert_equal("hi!!", Foo.hi)
end
