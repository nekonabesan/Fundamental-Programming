require __dir__ + '/../modules/fp_module.rb'
require 'benchmark'
require 'bigdecimal'
require 'bigdecimal/util'

def a_1(n)
  begin
    raise ArgumentError if n.nil? || n.zero?
    results = []
    obj = FpModule.new
    #/==============計測開始==============/
    time = Benchmark.realtime do
      for i in 2..n do
        sw = false
        #results.each{ |k| sw = true if i % k == 0 }
        results.each do |k|
          if i % k == 0 then
            sw = true
            break
          end
        end
        next if sw == true
        results.push(i) if obj.judgePno(i) == true
      end
    end
    puts("処理時間 #{time}s")
    #/=============計測終了===============/
    return results
  rescue => e
    return e
  end
end

def a_2(n)
  begin
    raise ArgumentError if n == nil
    obj = FpModule.new
    n = n.to_i.abs
    result = []
    #/==============計測開始==============/
    time = Benchmark.realtime do
      for i in 2..n do
        result.push(i) if obj.judgePno(i)
      end
    end
    puts("(全検索)処理時間 #{time}s")
    #/=============計測終了===============/
    return result
  rescue => e
    return e
  end
end
