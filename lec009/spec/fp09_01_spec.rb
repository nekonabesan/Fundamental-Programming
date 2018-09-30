require __dir__ + "/spec_helper"
require __dir__ + '/../fp09_01.rb'
require __dir__ + '/../app/models/dog.rb'


describe "演習 1" do
  context "Dog" do
    a = Dog.new("pochi")
    b = Dog.new("tama")
    it " a.talk" do
      results = a.talk
      expect(results).to match("my name is pochi")
    end
    it " b.talk" do
      results = b.talk
      expect(results).to match("my name is tama")
    end
    it "a.addspeed(5.0)" do
      results = a.addspeed(5.0)
      expect(results).to match("speed = 5.0")
    end
    it "b.addspeed(8.0)" do
      results = b.addspeed(8.0)
      expect(results).to match("speed = 8.0")
    end
    it "a.addspeed(10.0)" do
      results = a.addspeed(10.0)
      expect(results).to match("speed = 15.0")
    end
  end
end
