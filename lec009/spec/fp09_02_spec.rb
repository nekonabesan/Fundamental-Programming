require __dir__ + "/spec_helper"
require __dir__ + '/../fp09_02.rb'
require __dir__ + '/../app/models/memory.rb'
require __dir__ + '/../app/models/concat.rb'
require __dir__ + '/../app/models/memory2.rb'
=begin
演習 2 次のような機能と使い方を持つクラスを作成せよ。使用例の通りに使えることを確認すること。
=end
=begin
a. 「覚える」機能を持つクラス Memory。put(x) で与えた容を記憶し、get で取り出す。
=end
describe "演習 2" do
  context "Memory" do
    obj = Memory.new
    obj.put(5)
    it "get 5" do
      results = obj.get
      expect(results).to eq 5
    end
    it "get 5" do
      results = obj.get
      expect(results).to eq 5
    end
    it "get 10" do
      obj.put(10)
      results = obj.get
      expect(results).to eq 10
    end
  end
  context "Concat" do
    obj = Concat.new
    obj.add("This")
    it "add(This)" do
      results = obj.get
      expect(results).to eq "This"
    end
    it "add(is)" do
      obj.add("is")
      results = obj.get
      expect(results).to eq "Thisis"
    end
    it "add(a)" do
      obj.add("a")
      results = obj.get
      expect(results).to eq "Thisisa"
    end
    it "reset" do
      obj.reset
      obj.add("pen")
      results = obj.get
      expect(results).to eq "pen"
    end
  end
  context "Memory2" do
    obj = Memory2.new
    it ".put(1)" do
      obj.put(1)
      results = obj.get
      expect(results).to eq 1
    end
    it "put(3)" do
      obj.put(3)
      obj.put(5)
      results = obj.get
      expect(results).to eq 5
    end
    it "get" do
      results = obj.get
      expect(results).to eq 3
    end
    it "get" do
      results = obj.get
      expect(results).to eq nil
    end
    it "put(7)->put(9)->get" do
      obj.put(7)
      obj.put(9)
      results = obj.get
      expect(results).to eq 9
    end
    it "put(11)->get" do
      obj.put(11)
      results = obj.get
      expect(results).to eq 11
    end
    it "get" do
      results = obj.get
      expect(results).to eq 7
    end
  end
end
