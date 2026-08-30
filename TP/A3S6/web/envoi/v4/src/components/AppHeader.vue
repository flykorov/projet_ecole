<template>
  <div class="top-rect">
    <div class="t">V4</div>
  </div>
</template>

<script>
export default {
  name: 'AppHeader',
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
.top-rect {
  width: 100%;
  height: 50px;
  background-color: lightgreen;
  position: absolute;
  top: 0;
  left: 0;
}

.t {
  color: darkblue;
  font-weight: bold;
  text-align: right;
  line-height: 45px;
  font-size: 30px;
  margin-right: 10px;
}
</style>
