require 'benchmark'
require 'bigdecimal'
require 'bigdecimal/util'
require __dir__ + '/../modules/fp_module.rb'
require __dir__ + '/app/models/dog.rb'

=begin
演習 1 この例題を打ち込み動かせ。次に「ほえる」メソッド bark(引数無) と、「ほえる回数」を設
定するメソッド setcount(回数を渡す) を追加せよ。最初は 3 回ほえるものとする。
=end
def main
  a = Dog.new('pochi')
  b = Dog.new('tama')
  puts(a.talk)
  puts(b.talk)
  a.addspeed(5.0)
  b.addspeed(8.0)
  a.addspeed(10.0)
  a.setCount(3)
  a.bark
  return true
end
