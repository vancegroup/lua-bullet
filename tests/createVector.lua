vec = bullet.btVector3()
assert(vec:length() == 0)
-- TODO assert(vec.length == 0)
-- This can be done once .length is bound as a property
vec = bullet.btVector3(3, 4, 0)
assert(vec:length() == 5)
print "OK!"
