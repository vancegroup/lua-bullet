-- bitwise inclusive OR (http://ricilake.blogspot.com/2007/10/iterating-bits-in-lua.html)
function bitor(x, y)
	local function bit(p)
	  return 2 ^ (p - 1)  -- 1-based indexing
	end

	local function hasbit(x, p)
	  return x % (p + p) >= p
	end

	local function setbit(x, p)
	  return hasbit(x, p) and x or x + p
	end

	local function clearbit(x, p)
	  return hasbit(x, p) and x - p or x
	end
	
	local p = 1; 
	local z = 0; 
	local limit = x > y and x or y
	while p <= limit do
		if hasbit(x, p) or hasbit(y, p) then
			z = z + p
		end
		p = p + p
	end
	return z
end