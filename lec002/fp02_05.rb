require 'bigdecimal'
require 'bigdecimal/util'

def main(a,b)
  begin
    raise ArgumentError if a == nil || b == nil
    a.to_i.abs
    b.to_i.abs
    result = 0;
    if a > b then
      l = a
      s = b
    elsif b > a then
      l = b
      s = a
    elsif a == b then
      return a
    end
    for i in 1..s do
      if s % i == 0 && l % i == 0 then
        result = i
      end
    end
    return result
  rescue => e
    e
  end
end
