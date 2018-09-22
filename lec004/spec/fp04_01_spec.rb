require __dir__ + "/spec_helper"
require __dir__ + '/../fp04_01.rb'


describe "演習1" do
  it "Include Array 8" do
    results = e(8)
    expect(results).to match_array([8])
  end
  it "Include Array 5" do
    results = e(5)
    expect(results).to match_array([8,5])
  end
  it "Include Array 3" do
    results = e(3)
    expect(results).to match_array([8,5,3])
  end
  it "mul" do
    results = mul
    expect(results).to match_array([8,15])
  end
  it "add" do
    results = add
    expect(results).to match_array([23])
  end
  it "clear" do
    results = clear
    expect(results).to match_array([])
  end
  it "include Array 8" do
    results = e 8
    expect(results).to match_array([8])
  end
  it "include Array 5" do
    results = e 5
    expect(results).to match_array([8,5])
  end
  it "add" do
    results = add
    expect(results).to match_array([13])
  end
  it "include Array 3" do
    results = e 3
    expect(results).to match_array([13,3])
  end
  it "mul" do
    results = mul
    expect(results).to match_array([39])
  end
  context "a. 加える代わりに指定した値を引く機能 dec(x)。" do
    it "Clear Array" do
      results = clear
      expect(results).to match_array([])
    end
    it "include Array 5" do
      results = e 5
      expect(results).to match_array([5])
    end
    it "include Array 7" do
      results = e 7
      expect(results).to match_array([5,7])
    end
    it "dec" do
      results = dec
      expect(results).to match_array([-2])
    end
  end
  context "b. うっかり間違って reset した時にそれを取り消せる機能 undo" do
    it "Clear" do
      results = clear
      expect(results).to match_array([])
    end
    it "include Array 5" do
      results = e 5
      expect(results).to match_array([5])
    end
    it "include Array -2" do
      results = e -2
      expect(results).to match_array([5,-2])
    end
    it "include Array 0" do
      results = e 0
      expect(results).to match_array([5,-2,0])
    end
    it "Clear Array" do
      results = clear
      expect(results).to match_array([])
    end
    it "Undo" do
      results = undo
      expect(results).to match_array([5,-2,0])
    end
  end
  context "c. これまでに加えた (そして引いた) 値の一覧を表示した上で合計を表示する機能 list" do
    it "Clear Array" do
      results = clear
      expect(results).to match_array([])
    end
    it "Include Array 3" do
      results = e 3
      expect(results).to match_array([3])
    end
    it "Include Array 2" do
      results = e 2
      expect(results).to match_array([3,2])
    end
    it "Include Array 1" do
      results = e 1
      expect(results).to match_array([3,2,1])
    end
    it "add" do
      results = add
      expect(results).to match_array([3,3])
    end
    it "dec" do
      results = dec
      expect(results).to match_array([0])
    end
    it "list" do
      results = list
      expect(results).to match_array([6,[3, 2, 1]])
    end
  end
end
describe "演習1 例外ケース1" do
  before do
    clear
  end
  context "Exception e" do
    it "e" do
      results = e(nil)
      expect(results).to be_a(RuntimeError)
    end
  end
end
describe "演習1 例外ケース2" do
  before do
    clear
  end
  context "Exception e" do
    it "e" do
      results = e('')
      expect(results).to be_a(RuntimeError)
    end
  end
end
describe "演習1 例外ケース3" do
  before do
    clear
    e 'e'
    e 10
  end
  context "Exception add" do
    it "add" do
      results = add
      expect(results).to be_a(TypeError)
    end
  end
end
describe "演習1 例外ケース4" do
  before do
    clear
  end
  context "Exception " do
    it "mul" do
      results = mul
      expect(results).to be_a(NoMethodError)
    end
  end
end
describe "演習1 例外ケース5" do
  before do
    clear
  end
  context "Exception " do
    it "dec" do
      results = dec
      expect(results).to be_a(NoMethodError)
    end
  end
end
=begin
演習2
=end
describe "演習2" do
  before do
    clear
    e 10
    e 2
  end
  context "a. 除算 (div)を追加。" do
    it "div" do
      results = div
      expect(results).to match_array([5])
    end
  end
end
describe "演習2" do
  before do
    clear
    e 10
    e 8
  end
  context "a. 除算 (div)を追加。" do
    it "div" do
      results = div
      expect(results).to match_array([1])
    end
  end
end
describe "演習2" do
  before do
    clear
    e 2
    e 5
  end
  context "a. 除算 (div)を追加。" do
    it "div" do
      results = div
      expect(results).to match_array([0])
    end
  end
end
describe "演習2" do
  before do
    clear
    e 2
    e 0
  end
  context "a. 除算 (div)を追加。" do
    it "div" do
      results = div
      expect(results).to be_a(ZeroDivisionError)
    end
  end
end
describe "演習2" do
  before do
    clear
    e 111
    e 111
  end
  context "a. 剰余 (mod)を追加。" do
    it "mod" do
      results = mod
      expect(results).to match_array([0])
    end
  end
end
describe "演習2" do
  before do
    clear
    e 11
    e 10
  end
  context "a. 剰余 (mod)を追加。" do
    it "mod" do
      results = mod
      expect(results).to match_array([1])
    end
  end
end
describe "演習2" do
  before do
    clear
    e 8
    e 0
  end
  context "a. 剰余 (mod)を追加。" do
    it "mod" do
      results = mod
      expect(results).to be_a(ZeroDivisionError)
    end
  end
end
describe "演習2" do
  before do
    clear
    e 1
    e 2
    add
  end
  context "b. 現在の演算結果の符号を反転する操作 inv。" do
    it "inv" do
      results = inv
      expect(results).to match_array([-3])
    end
  end
end
describe "演習2" do
  before do
    clear
    e -1
    e -2
    add
  end
  context "b. 現在の演算結果の符号を反転する操作 inv。" do
    it "inv" do
      results = inv
      expect(results).to match_array([3])
    end
  end
end
describe "演習2" do
  before do
    clear
  end
  context "b. 現在の演算結果の符号を反転する操作 inv。" do
    it "inv" do
      results = inv
      expect(results).to be_a(NoMethodError)
    end
  end
end
describe "演習2" do
  before do
    clear
    e 1
    e 2
  end
  context "c. 最後の結果と 1 つ前の結果を交換する操作 exch。" do
    it "inv" do
      results = exch
      expect(results).to match_array([2,1])
    end
  end
end
