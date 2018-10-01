require '../modules/fp_module.rb'
require './fp07_01.rb'
require './fp07_02.rb'
require './fp07_05.rb'
require './fp07_06.rb'

=begin
=end
def fp07_01(times)
  begin
    raise ArgumentError if times.nil? || times.zero?
    obj = FpModule.new
    a = obj.randarray(times.to_i)
    time = obj.bench do
      selectionsort(a)
    end
    return time
  rescue => e
    return e
  end
end

=begin
=end
def fp07_02(times)
  begin
    raise ArgumentError if times.nil? || times.zero?
    obj = FpModule.new
    a = obj.randarray(times.to_i)
    time = obj.bench do
      insertionsort(a)
    end
    return time
  rescue => e
    return e
  end
end

=begin
=end
def fp07_05(times)
  begin
    raise ArgumentError if times.nil? || times.zero?
    obj = FpModule.new
    a = obj.randarray(times.to_i)
    time = obj.bench do
      binsort(a)
    end
    return time
  rescue => e
    return e
  end
end

=begin
=end
def fp07_06(times)
  begin
    raise ArgumentError if times.nil? || times.zero?
    obj = FpModule.new
    a = obj.randarray(times.to_i)
    time = obj.bench do
      radixsort(a)
    end
    return time
  rescue => e
    return e
  end
end
